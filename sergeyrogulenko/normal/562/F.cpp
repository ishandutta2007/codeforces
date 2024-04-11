#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_DEPRECATE

#include<set>
#include<map>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<bitset>
#include<cmath>
#include<complex>
#include<ctime>
#include<iostream>
#include<sstream>
#include<vector>

#define next nexthui
#define prev prevhui
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define fs first
#define sc second
#define all(x) x.begin(), x.end()
#define sqr(x) ((x)*(x))
#define last(x) ((int)x.size()-1)

using namespace std;

typedef long long int64;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = (1 << 30) - 1;
const int64 INF64 = (1LL << 62) - 1;
const ldb EPS = 1e-9;

const int SMAX = 1100000;
const int NMAX = 210000;

char buf[SMAX];
string s[2][NMAX];
int nn = 1, g[SMAX][26], tp[NMAX], id[NMAX], st[SMAX], sz, deep[SMAX], m, lcp[NMAX], p[NMAX];
vector<pair<int, int> > en[SMAX], fr[NMAX], ans;
int64 gl, sum;

void add(const string& s, int tp, int id) {
    int v = 0;
    forn(i, s.size()) {
        int to = g[v][s[i] - 'a'];
        if (to == -1) {
            g[v][s[i] - 'a'] = nn++;
        }
        v = g[v][s[i] - 'a'];
    }
    en[v].pb(mp(tp, id));
}

void dfs(int v, int dp) {
    bool gg = true;
    forn(i, en[v].size()) {
        if (m) {
            if (!gg)
                lcp[m - 1] = dp;
            else
                lcp[m - 1] = deep[st[sz - 1]];
        }
        tp[m] = en[v][i].fs;
        id[m++] = en[v][i].sc;
        gg = false;
    }
    deep[v] = dp;

    if (en[v].size())
        st[sz++] = v;
        
    bool f = true;
    forn(i, 26) {
        if (g[v][i] == -1)
            continue;
        if (!f)
            st[sz++] = v;
        dfs(g[v][i], dp + 1);
        if (!f)
            sz--;
        f = false;
    }

    if (en[v].size())
        sz--;
}

int get(int v) {
    if (v == p[v])
        return v;

    return p[v] = get(p[v]);
}

void unite(int v1, int v2) {
    if (v1 == v2)
        throw;

    if (fr[v1].empty()) {
        p[v1] = v2;
        return;
    }
    if (fr[v2].empty()) {
        p[v2] = v1;
        return;
    }

    if (fr[v1][0].fs != fr[v2][0].fs) {
        while (fr[v1].size() && fr[v2].size()) {
            int a1 = fr[v1].back().sc;
            int a2 = fr[v2].back().sc;
            if (fr[v1][0].fs == 1)
                swap(a1, a2);
            fr[v1].pop_back();
            fr[v2].pop_back();
            ans.pb(mp(a1, a2));
            sum += gl;
        }
    }

    if (fr[v1].size() < fr[v2].size()) {
        fr[v2].insert(fr[v2].end(), all(fr[v1]));
        fr[v1].clear();
        p[v1] = v2;
    }
    else {
        fr[v1].insert(fr[v1].end(), all(fr[v2]));
        fr[v2].clear();
        p[v2] = v1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    memset(g, -1, sizeof(g));

    forn(j, 2)
        forn(i, n) {
            scanf("%s", buf);
            s[j][i] = buf;
            add(s[j][i], j, i);
        }

    dfs(0, 0);

    if (m != 2 * n)
        throw;

    vector<pair<int, pair<int, int> > > e;
    forn(i, m - 1)
        e.pb(mp(lcp[i], mp(i, i + 1)));

    sort(all(e));
    reverse(all(e));

    forn(i, m) {
        p[i] = i;
        fr[i].pb(mp(tp[i], id[i]));
    }

    forn(i, e.size()) {
        int v1 = e[i].sc.fs;
        int v2 = e[i].sc.sc;

        v1 = get(v1);
        v2 = get(v2);

        gl = e[i].fs;
        unite(v1, v2);
    }

    cout << sum << endl;
    forn(i, n)
        printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);
}