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

typedef pair<int,int> pt;
#define ft first
#define sc second

int m, k;
vector<pt> edge;

vector<int> x;

bool read() {
    if (!(cin >> m >> k))
        return false;
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        x.pb(a);
        x.pb(b);
        edge.pb(mp(a, b));
    }
    return true;
}

const int N = 500;
vector<int> g[N];

void solve() {
    
    sort(all(x));
    x.resize(unique(all(x)) - x.begin());
    
    forn (i, edge.size()) {
        int a = lower_bound(x.begin(), x.end(), edge[i].ft) - x.begin();
        int b = lower_bound(x.begin(), x.end(), edge[i].sc) - x.begin();
        g[a].pb(b);
        g[b].pb(a);
    }

    forn (i, N) {
        sort(all(g[i]));
        g[i].resize(unique(all(g[i])) - g[i].begin());
    }

    forn (i, x.size()) {
        vector<int> ans;
        cout << x[i] << ": ";

        forn (j, x.size()) {
            if (j == i || binary_search(g[i].begin(), g[i].end(), j))
                continue;
            int cnt = 0;
            forn (t, g[i].size()) {
                int f = g[i][t];
                if (binary_search(g[f].begin(), g[f].end(), j))
                    cnt++;
            }
            if (100 * cnt >= g[i].size() * k)
                ans.pb(j);
        }

        cout << ans.size();
        forn (t, ans.size())
            cout << " " << x[ans[t]];
        cout << endl;
    }
}

int main() {

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else

#ifdef TASK_NAME
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif

#endif

    while (read())
        solve();
    
    return 0;
}