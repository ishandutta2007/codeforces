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

const int N = 505;
int a[N], b[N];
int n, m;

bool read() {
    
    if (!(cin >> n))
        return false;
    forn (i, n)
        cin >> a[i];
    cin >> m;
    forn (i, m)
        cin >> b[i];

    return true;
}

pair<int, pt> f[N][N];

void add(int x, int y, int d) {
    pair<int, pt> cur = mp(d, mp(x, y));
    for (int i = x; i < N; i |= i + 1)
        for (int j = y; j < N; j |= j + 1)
            f[i][j] = max(f[i][j], cur);
}

pair<int, pt> get(int x, int y) {
    pair<int, pt> res = mp(0, mp(-1, -1));
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
            res = max(res, f[i][j]);
        }
    }
    return res;
}

vector<int> xc;

int id(int x) {
    return lower_bound(all(xc), x) - xc.begin();
}

pt from[N][N];
int dp[N][N];

void solve() {
    
    xc.clear();

    forn (i, N)
        forn (j, N) {
            f[i][j] = mp(0, mp(-1, -1));
            dp[i][j] = 0;
        }

    forn (i, n)
        xc.pb(a[i]);
    forn (i, m)
        xc.pb(b[i]);

    sort(all(xc));

    xc.resize(unique(all(xc)) - xc.begin());

    vector<int> posa[2 * N];
    forn (i, n)
        posa[id(a[i])].pb(i);

    vector<int> posb[2 * N];
    forn (i, m)
        posb[id(b[i])].pb(i);

    forn (cur, xc.size()) {
        for (int i = posa[cur].size() - 1; i >= 0; --i)
            for (int j = posb[cur].size() - 1; j >= 0; --j) {
                pair<int, pt> v = get(posa[cur][i] - 1, posb[cur][j] - 1);
                dp[posa[cur][i]][posb[cur][j]] = v.ft + 1;
                from[posa[cur][i]][posb[cur][j]] = v.sc;
                add(posa[cur][i], posb[cur][j], v.ft + 1);
            }
    }

    pt ans = mp(0, 0);

    forn (i, n)
        forn (j, m)
            if (dp[i][j] > dp[ans.ft][ans.sc])
                ans = mp(i, j);

    int answer = dp[ans.ft][ans.sc];

    cout << answer << endl;
    
    if (answer == 0)
        return;

    vector<int> res;

    do {
        res.pb(a[ans.ft]);
        ans = from[ans.ft][ans.sc];
    } while(ans.ft != -1);

    reverse(all(res));

    assert(res.size() == answer);
    forn (i, res.size() - 1)
        assert(res[i] < res[i + 1]);

    forn (i, res.size())
        cout << res[i] << ' ';
    cout << endl;

}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    while(read())
        solve();

    return 0;
}