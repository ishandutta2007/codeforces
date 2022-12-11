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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 300300;

int n, m;
vector<int> g[nmax];
int used[nmax], pos[nmax];
vector<int> t;

void dfs(int v) {
    used[v] = 1;
    forn(i, g[v].size())
        if (!used[g[v][i]])
            dfs(g[v][i]);
    t.pb(v);
}

void add(int v, int u) {
    g[v].pb(u);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n>> m;
    int sz = m;
    forn(i, n) {
        vector<pii> a(m);
        vector<int> w, in, out;
        forn(j, m) {
            scanf("%d", &a[j].fs);
            a[j].sc = j;
            if (a[j].fs != -1) w.pb(a[j].fs);
        }   
        sort(all(a));
        sort(all(w));
        w.erase(unique(all(w)), w.end());
        in.resize(w.size());
        out.resize(w.size());
        forn(j, w.size()) {
            in[j] = sz ++;
            out[j] = sz ++;
        }

        forn(j, m) {
            if (a[j].fs == -1)
                continue;
            int now = lower_bound(all(w), a[j].fs) - w.begin();
            add(a[j].sc, in[now]);
            add(out[now], a[j].sc);
        }
        forn(i, w.size() - 1)
            add(in[i + 1], out[i]);
    }
    forn(i, sz)
        if (!used[i])
            dfs(i);
    forn(i, t.size())
        pos[t[i]] = i;
    forn(i, sz)
        forn(j, g[i].size())
            if (pos[g[i][j]] > pos[i]) {
                puts("-1");
                exit(0);
            }
    forn(i, t.size())
        if (t[i] < m)
            printf("%d ", t[i] + 1);
    puts("");

    return 0;
}