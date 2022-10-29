#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

int n, m;
const int N = 505;
vector<int> g[N];

bool read() {
    if (!(cin >> n >> m))
        return false;
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    return false;
}

int d[N][N][2];
pair<pt, int> from[N][N][2];

void solve() {
    forn (i, N)
        forn (j, N)
        forn (k, 2)
        d[i][j][k] = INF;
    d[0][n - 1][0] = 0;
    queue<pair<pt, int>> q;
    q.push(mp(mp(0, n - 1), 0));
    while(!q.empty()) {
        pt v = q.front().ft;
        int cur = q.front().sc;
        q.pop();
        if (cur == 0) {
            forn (i, g[v.ft].size()) {
                int to = g[v.ft][i];
                if (d[to][v.sc][1] == INF) {
                    d[to][v.sc][1] = d[v.ft][v.sc][0] + 1;
                    from[to][v.sc][1] = mp(v, cur);
                    q.push(mp(mp(to, v.sc), 1));
                }
            }
        } else {
            forn (i, g[v.sc].size()) {
                int to = g[v.sc][i];
                if (to == v.ft)
                    continue;
                if (d[v.ft][to][0] == INF) {
                    d[v.ft][to][0] = d[v.ft][v.sc][1] + 1;
                    from[v.ft][to][0] = mp(v, cur);
                    q.push(mp(mp(v.ft, to), 0));
                }
            }
        }
    }
    if (d[n - 1][0][0] == INF)
        cout << -1 << endl;
    else {
        cout << d[n - 1][0][0] / 2 << endl;
        vector<int> ans[2];
        ans[1].pb(0);
        pair<pt, int> cur = mp(mp(n - 1, 0), 0);
        while(cur != mp(mp(0, n - 1), 0)) {
            if (cur.sc)
                ans[1].pb(cur.ft.sc);
            else
                ans[0].pb(cur.ft.ft);
            cur = from[cur.ft.ft][cur.ft.sc][cur.sc];
        }
        ans[0].pb(0);
        forn (i, 2) {
            reverse(all(ans[i]));
            forn (j, ans[i].size())
                cout << ans[i][j] + 1 << ' ';
            cout << endl;
        }
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    read();
    solve();
    
    return 0;
}