#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

bool cyc;
int sz;
int use[N];
bool used[N];
int lst[N];
vi g[N], g2[N];

void dfs1(int v) {
    used[v] = true;
    lst[sz++] = v;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (!used[g[v][i]]) {
            dfs1(g[v][i]);
        }
    }
}

void dfs2(int v) {
    use[v] = 1;
    for (int i = 0; i < sz(g2[v]); ++i) {
        if (use[g2[v][i]] == 0) {
            dfs2(g2[v][i]);
        } else if (use[g2[v][i]] == 1) {
            cyc = true;
        }
    }
    use[v] = 2;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
        g2[a].pb(b);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            sz = 0;
            dfs1(i);
            cyc = false;
            for (int j = 0; j < sz; ++j) {
                if (use[lst[j]] == 0) {
                    dfs2(lst[j]);
                }
            }
            if (cyc) {
                ans += sz;
            } else {
                ans += sz - 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}