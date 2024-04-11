#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const ll linf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int LOG = 60;
const int N = int(1e6) + 100;
const int MOD = int(1e9) + 7;

struct edge {
    
    int go, num;
    ll val;
    
    edge() {}
    
    edge(int go, int num, ll val) : go(go), num(num), val(val) {}
    
};

int sz;
bool used[N], used_edge[N];
ll sum[N];
vector<edge> g[N];
ll a[N];
int cnt[LOG][2];

void dfs(int v, ll sum) {
    used[v] = true;
    ::sum[v] = sum;
    for (int i = 0; i < LOG; ++i) {
        ++cnt[i][(sum >> i) & 1];
    }
    for (edge e : g[v]) {
        if (!used[e.go]) {
            used_edge[e.num] = true;
            dfs(e.go, sum ^ e.val);
        } else {
            a[sz++] = ::sum[v] ^ ::sum[e.go] ^ e.val;
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        --a;
        --b;
        g[a].emplace_back(b, i, c);
        g[b].emplace_back(a, i, c);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            sz = 0;
            for (int j = 0; j < LOG; ++j) {
                cnt[j][0] = cnt[j][1] = 0;
            }
            dfs(i, 0);
            int rank = 0;
            ll msk = 0;
            for (int j = 0; j < LOG; ++j) {
                int pos = -1;
                for (int z = rank; z < sz; ++z) {
                    if ((a[z] & (1LL << j)) != 0) {
                        pos = z;
                        break;
                    }
                }
                if (pos != -1) {
                    swap(a[rank], a[pos]);
                    msk |= a[rank];
                    for (int z = rank + 1; z < sz; ++z) {
                        if ((a[z] & (1LL << j)) != 0) {
                            a[z] ^= a[rank];
                        }
                    }
                    ++rank;
                }
            }
            for (int j = 0; j < LOG; ++j) {
                int val = (1LL << j) % MOD, can;
                if ((msk & (1LL << j)) != 0) {
                    can = (1LL * (cnt[j][0] + cnt[j][1]) * (cnt[j][0] + cnt[j][1] - 1) / 2) % MOD;
                    can = ((1LL << (rank - 1)) % MOD * can) % MOD;
                } else {
                    can = (1LL * cnt[j][0] * cnt[j][1]) % MOD;
                    can = ((1LL << rank) % MOD * can) % MOD;
                }
                ans = (ans + 1LL * val * can) % MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}