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

const int N = 200 * 1000 + 5;

int n, m, k, q;
int x[N], y[N];

pair <pt, pt> qr[N];
bool ans[N];

bool read() {
    if (scanf("%d %d %d %d", &n, &m, &k, &q) != 4)
        return false;
    
    forn(i, k) {
        scanf("%d %d", &x[i], &y[i]);
        --x[i], --y[i];
    }

    forn(i, q) {
        scanf("%d %d %d %d", &qr[i].ft.ft, &qr[i].ft.sc, &qr[i].sc.ft, &qr[i].sc.sc);
        --qr[i].ft.ft;
        --qr[i].ft.sc;
        --qr[i].sc.ft;
        --qr[i].sc.sc;
    }

    return true;
}

int st[4 * N];
vector <int> qs[N], ks[N];

void update(int v, int l, int r, int key, int value) {
    if (l == r) {
        assert(l == key);
        st[v] = value;
        return;
    }

    int m = (l + r) >> 1;
    if (key <= m)
        update(v * 2 + 1, l, m, key, value);
    else
        update(v * 2 + 2, m + 1, r, key, value);

    st[v] = min(st[v * 2 + 1], st[v * 2 + 2]);
}

int get(int v, int l, int r, int L, int R) {
    if (l == L && r == R)
        return st[v];

    int m = (l + r) >> 1;

    if (R <= m)
        return get(v * 2 + 1, l, m, L, R);

    if (L > m)
        return get(v * 2 + 2, m + 1, r, L, R);

    return min(
        get(v * 2 + 1, l, m, L, m),
        get(v * 2 + 2, m + 1, r, m + 1, R)
    );
}

void do_solve() {
    memset(st, -1, sizeof st);

    forn(i, m)
        qs[i].clear();

    forn(i, q)
        qs[ qr[i].sc.sc ].pb(i);

    forn(i, m)
        ks[i].clear();

    forn(i, k)
        ks[ y[i] ].pb(i);

    forn(y, m) {
        forn(j, sz(ks[y])) {
            int i = ks[y][j];
            update(0, 0, n - 1, x[i], y);
        }

        forn(j, sz(qs[y])) {
            int i = qs[y][j];
            ans[i] |= get(0, 0, n - 1, qr[i].ft.ft, qr[i].sc.ft) >= qr[i].ft.sc;
        }
    }
}

void solve() {
    memset(ans, 0, sizeof ans);
    do_solve();

    swap(n, m);

    forn(i, k)
        swap(x[i], y[i]);

    forn(i, q) {
        swap(qr[i].ft.ft, qr[i].ft.sc);
        swap(qr[i].sc.ft, qr[i].sc.sc);
    }

    do_solve();

    forn(i, q)
        puts(ans[i] ? "YES" : "NO");
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