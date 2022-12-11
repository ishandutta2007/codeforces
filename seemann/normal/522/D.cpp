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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) mem_set(a, 0, sizeof(a))

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 5e5 + 100;
const int MAXT = 5 * MAXN;

int a[MAXN];
int _prev[MAXN];
int ans[MAXN];
map<int, int> last;

struct query {
    int l, r;
    int n;
};

bool operator < (const query & a, const query & b) {
    return a.r < b.r;
}
query q[MAXN];

int t[MAXT];

void _set(int v, int l, int r, int p, int val) {
    if (p < l || p >= r)
        return;
    if (p == l && r == l + 1) {
        t[v] = val;
        return;
    }
    _set(2 * v + 1, l, (l + r) / 2, p, val);
    _set(2 * v + 2, (l + r) / 2, r, p, val);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

int get(int v, int l, int r, int lq, int rq) {
    if (rq <= l || r <= lq)
        return INF;
    if (lq <= l && r <= rq)
        return t[v];
    return min(get(2 * v + 1, l, (l + r) / 2, lq, rq),
            get(2 * v + 2, (l + r) / 2, r, lq, rq));
}


int main() {
	//freopen("d.in", "r", stdin);
	//freopen("d.out", "w", stdout);
	//freopen("", "w", stderr);
    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, n) {
        scanf("%d", &a[i]);
    }
    FOR(i, n) {
        if (last.count(a[i]) == 0)
            _prev[i] = -1;
        else
            _prev[i] = last[a[i]];
        last[a[i]] = i;
    }
    FOR (i, m) {
        int l, r;
        scanf("%d%d", &l, &r);
        q[i].n = i;
        q[i].l = --l;
        q[i].r = r;
    }
    sort(q, q + m);
    FOR(i, MAXT)
        t[i] = INF;
    int sz = 1;
    while (sz < n)
        sz *= 2;
    int lastr = 0;
    FOR(i, m) {
        for (int j = lastr; j < q[i].r; ++j) {
            if (_prev[j] != -1)
                _set(0, 0, sz, _prev[j], j - _prev[j]);
        }
        lastr = q[i].r;
        ans[q[i].n] = get(0, 0, sz, q[i].l, q[i].r);
    }
    FOR(i, m) {
        if (ans[i] == INF)
            printf("-1\n");
        else
            printf("%d\n", ans[i]);

    }


	return 0;
}