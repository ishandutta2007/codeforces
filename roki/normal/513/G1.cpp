#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:167772016")

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()

typedef long long li;
typedef double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9) + 6;
const li INF64 = li(1e18);
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

const int N = 50000;
vector<int> a;
int n, k;

bool read() {
    cin >> n >> k;
    a.resize(n);
    forn (i, n) {
        cin >> a[i];
        a[i]--;
    }
    return true;
}

vector<int> g[N];

int encode(vector<int>& v) {
    int res = 0;
    forn (i, n) {
        res *= 6;
        res += v[i];
    }
    return res;
}

vector<int> decode(int x) {
    vector<int> v(n);
    forn (i, n) {
        v[n - 1 - i] = x % 6;
        x /= 6;
    }
    return v;
}

int inv[N];

void rev(vector<int>& v, int l, int r) {
    while (r > l)
        swap(v[l++], v[r--]);
}

void addE(vector<int>& v) {
    int cur = encode(v);
    inv[cur] = 0;
    forn (i, n) {
        forn (j, i)
            if (v[j] > v[i])
                inv[cur]++;
    }

    forn (i, n)
        forn (j, i + 1) {
            rev(v, j, i);
            int nt = encode(v);
            g[cur].pb(nt);
            rev(v, j, i);
        }
}

int cnt[N][5];

void solve() {
    vector<int> v(n);
    forn (i, n)
        v[i] = i;
    do {
        addE(v);
    } while(next_permutation(all(v)));
    int cur = encode(a);
    cnt[cur][0] = 1;
    forn (j, 4)
        forn (v, N) {
            forn (i, g[v].size()) {
                int to = g[v][i];
                cnt[to][j + 1] += cnt[v][j];
            }
        }
    int sum = 0;
    forn (i, N)
        sum += cnt[i][k];
    ld ans = 0;
    forn (i, N)
        ans += 1.0 * cnt[i][k] * inv[i] / sum;
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    read();
    solve();

    return 0;
}