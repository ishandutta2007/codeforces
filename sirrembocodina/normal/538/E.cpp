#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;

vector<int> g[200100];
int n, sz[200100], ans[200100];

void dfs(int v) {
    if (g[v].size() == 0) {
        sz[v] = 1;
        return;
    }
    sz[v] = 0;
    forn (i, g[v].size()) {
        dfs(g[v][i]);
        sz[v] += sz[g[v][i]];
    }
}

int solve(int v, bool mx) {
    ans[v] = 1;
/*    if (g[v].size() == 0) {
        return ans[v];
    }*/
    forn (i, g[v].size()) {
        solve(g[v][i], !mx);
    }
    if (mx) {
        forn (i, g[v].size()) {
            ans[v] = max(ans[v], sz[v] - sz[g[v][i]] + ans[g[v][i]]);
        }
    } else {
        forn (i, g[v].size()) {
            ans[v] += ans[g[v][i]] - 1;
        }
    }
//    cerr << v << " " << ans[v] << endl;
    return ans[v];
}

int main() {
    cin >> n;
    forn (i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].pb(b);
    }
    dfs(0);
    cout << solve(0, true) << " " << sz[0] + 1 - solve(0, false) << endl;
    return 0;
}