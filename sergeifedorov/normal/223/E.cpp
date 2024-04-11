#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

#define x first
#define y second

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 100100;

int n, m;
pii p[nmax];
vector<int> g[nmax], s[nmax];
map<int, int> pos[nmax];
map<int, int> cost[nmax];
bool used[nmax];
int tmp[nmax];


double getAngle(pii a, pii b) {
    return atan2(a.y - b.y + .0, a.x - b.x + .0);
}

int dfs(int rt) {
    used[rt] = 1;
    int res = 1;
    forn(i, g[rt].size()) {
        if (!used[g[rt][i]]) {
            int now = dfs(g[rt][i]);
            cost[rt][g[rt][i]] = now;
            cost[g[rt][i]][rt] = -now;
            res += now;
        }
    }
    return res;
}

void pre_calc() {
    int rt = 0;
    forn(i, n)
        if (p[rt] > p[i])
            rt = i;
    p[n] = p[rt];
    p[n].fs --;
    p[n].sc --;
    g[n].pb(rt);
    g[rt].pb(n);
    dfs(n);
    n ++;
    forn(i, n) {
        vector<pair<double, int> > e;
        s[i].assign(g[i].size() + 1, 0);
        forn(j, g[i].size()) {
            e.pb(mp(getAngle(p[i], p[g[i][j]]), g[i][j]));
        }
        sort(all(e));
        forn(j, g[i].size()) {
            g[i][j] = e[j].sc;
            pos[i][g[i][j]] = j;
            s[i][j + 1] = cost[i][g[i][j]];
        }
        forn(j, g[i].size()) 
            s[i][j+1] += s[i][j];
    }
}

int get(int v, int a, int b) {
    int pa = pos[v][a];
    int pb = pos[v][b];
    int res = 0;
    if (pa > pb)
        res = s[v].back() - s[v][pa+1] + s[v][pb];
    else
        res = s[v][pb] - s[v][pa+1];
    return res;
}

int solve(int k) {
    int res = 0;
    forn(i, k)
        res += get(tmp[i], tmp[(i - 1 + k) % k], tmp[(i + 1) % k]);
    return abs(res);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

     cin >> n >> m;
     forn(i, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u --; v--;
        g[u].pb(v);
        g[v].pb(u);
     }
     forn(i, n)
        scanf("%d %d", &p[i].x, &p[i].y);

     pre_calc();
//     cerr << "here" << endl;

     int tst;
     cin >> tst;
     forn(qwe, tst) {
        int k;
        scanf("%d", &k);
        forn(i, k) {
            scanf("%d", &tmp[i]);
            tmp[i] --;
        }
        int res = solve(k);
        forn(i, k / 2)
            swap(tmp[i], tmp[k - i - 1]);
        res = max(res, solve(k));
//      cerr << res << endl;
        printf("%d\n", res);
     }

    return 0;
}