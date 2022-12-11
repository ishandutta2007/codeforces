#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9 + 100;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 4e5 + 1000;

struct query {
    int h, n;
};
vector<query> q[MAXN];
int ans[MAXN];
int h[MAXN];
int bh[MAXN], bi[MAXN];
int ina[MAXN];
int n, m;
int qi[MAXN];
int pr[MAXN];

int lst;
void getdp() {
    forn(i, n + 1) {
        bh[i] = INF;
        pr[i] = -1;
    }
    bh[0] = -INF;
    bi[0] = -1;
    forn(i, n) {
    /*    forn(i, n)
            cerr << bh[i] << ' ';
        cerr << '\n';*/
        for (auto j : q[i]) {
            int pos = lower_bound(bh, bh + n + 1, j.h) - bh - 1;
            ans[j.n] += pos;
        }
        int pos = lower_bound(bh, bh + n + 1, h[i]) - bh - 1;
        pr[i] = bi[pos];
        if (bh[pos + 1] >= h[i]) {
            bh[pos + 1] = h[i];
            bi[pos + 1] = i;
        }
    }
     
    int best = 0;
    lst = 0;
    for (int i = n; i >= 0; --i) {
        if (bh[i] < INF) {
            best = bi[i];
            lst = i;
            break;
        }
    }
    int i = best;
    while (i >= 0) {
        ina[i]++;
        i = pr[i];
    }
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%d", &h[i]);
    }
    forn(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        qi[i] = a;
        q[a].push_back({b, i});
    }

    getdp();
    reverse(h, h + n);
    reverse(q, q + n);
    forn(i, n) {
        h[i] = - h[i];
        forn(j, q[i].size()) {
            q[i][j].h *= -1;
        }
    }
    reverse(ina, ina + n);
    getdp();
    reverse(ina, ina + n);
    forn(i, m) {
        int na = lst;
        if (ina[qi[i]] == 2) {
            na--;
        }
        ans[i] = max(ans[i] + 1, na);
        printf("%d\n", ans[i]);
    }



    
    return 0;
}