#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
ll rnd() {
    return (rand() + (ll)rand() * RAND_MAX);
}
struct node {
    int x;
    int s;
    int l, r;
    node() {
        x = 0;
        s = 1;
        l = 0;
        r = 0;
    }
};
int root1 = 0;
int root2 = 0;
const int MX = 10000000;
node a[MX + 10];
int Q[MX + 10];
int was[MX + 10];

int L = 0;
int R = 0;      
int cnt = 0;
void dfs(int v) {
    if (v == 0) return;
    dfs(a[v].l);
    dfs(a[v].r);
    was[v] = cnt;
}
void recalc() {
    cnt++;    
    dfs(root1);
    dfs(root2);
    L = 0;
    R = 0;
    for (int i = 1; i <= MX; i++) {
        if (was[i] != cnt) {
            Q[R++] = i;
        }
    }
}
inline int rnd(const int& k) {
    return (rand() + (ll)rand() * RAND_MAX) % k;
}
void upd(int v) {
    if (v == 0) return;
    a[v].s = a[a[v].l].s + a[a[v].r].s + 1;
}
inline int next() {    
    return Q[L++];
}
void split(int v, int k, int& l, int& r) {
    l = 0;
    r = 0;
    if (v == 0) {
        return;
    }
    int tmp;
    int vv = next();
    if (a[a[v].l].s >= k) {
        split(a[v].l, k, l, tmp);
        a[vv] = a[v];
        a[vv].l = tmp;
        r = vv;
    } else {
        split(a[v].r, k - 1 - a[a[v].l].s, tmp, r);
        a[vv] = a[v];
        a[vv].r = tmp;
        l = vv;
    }
    upd(l);
    upd(r);
}
int merge(int l, int r) {
    if (l == 0 || r == 0) return l + r;
    int tmp = 0;
    int vv = next();
    if (rnd(a[l].s + a[r].s) < a[l].s) {
        tmp = merge(a[l].r, r);
        a[vv] = a[l];
        a[vv].r = tmp;
    } else {
        tmp = merge(l, a[r].l);
        a[vv] = a[r];
        a[vv].l = tmp;
    }
    upd(vv);
    return vv;
}
int get(int v, int k) {
    if (k == a[a[v].l].s + 1) {
        return a[v].x;
    }
    if (a[a[v].l].s >= k) {
        return get(a[v].l, k);
    } else {
        return get(a[v].r, k - 1 - a[a[v].l].s);
    }
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    a[0].s = 0;
    srand(239);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= MX; i++) {
        Q[R++] = i;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int vv = next();
        a[vv].x = x;
        root1 = merge(root1, vv);
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int vv = next();
        a[vv].x = x;
        root2 = merge(root2, vv);
    }    
    for (int i = 0; i < m; i++) {
        int t, x, y, z;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d %d", &x, &y, &z);
            int lf, md, rg;
            int lf2, md2, rg2;
            split(root1, x + z - 1, lf, rg);
            split(lf, x - 1, lf, md);
            split(root2, y + z - 1, lf2, rg2);
            split(lf2, y - 1, lf2, md2);
            root2 = merge(lf2, md);
            root2 = merge(root2, rg2);
        } else {
            scanf("%d", &x);
            printf("%d\n", get(root2, x));
        }
        if (R - L < 1000) {
            recalc();
        }
    }
    
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}