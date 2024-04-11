#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int N = int(1e5) + 100;
const int MOD = int(1e9) + 7;

bool used[N];
vi g[N];
vi sons;
int p[N], x[N];
int d[N][2], f[N][2];

inline void add(int &a, int b, int c) {
    a = (a + 1LL * b * c) % MOD;
}

void dfs(int v) {
    used[v] = true;
    bool leaf = true;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (!used[g[v][i]]) {
            p[g[v][i]] = v;
            dfs(g[v][i]);
            leaf = false;
        }
    }
    if (leaf) {
        if (x[v]) {
            d[v][1] = 1;
        } else {
            d[v][0] = 1;
        }
        return;
    }
    sons.clear();
    for (int i = 0; i < sz(g[v]); ++i) {
        if (p[g[v][i]] == v) {
            sons.pb(g[v][i]);
        }
    }
    for (int i = 0; i <= sz(sons); ++i) {
        f[i][0] = f[i][1] = 0;
    }
    f[0][0] = 1;
    for (int i = 0; i < sz(sons); ++i) {
        for (int j = 0; j < 2; ++j) {
            if (f[i][j] == 0) {
                continue;
            }
            // cut
            add(f[i + 1][j], f[i][j], d[sons[i]][1]);
            // not-cut
            add(f[i + 1][j], f[i][j], d[sons[i]][0]);
            if (j == 0) {
                add(f[i + 1][1], f[i][j], d[sons[i]][1]);
            }
        }
    }
    if (x[v]) {
        d[v][0] = 0;
        d[v][1] = f[sz(sons)][0];
    } else {
        d[v][0] = f[sz(sons)][0];
        d[v][1] = f[sz(sons)][1];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p);
        g[p].pb(i);
        g[i].pb(i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    p[0] = -1;
    dfs(0);
    cout << d[0][1] << endl;
    return 0;
}