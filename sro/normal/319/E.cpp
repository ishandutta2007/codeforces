/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

template<int siz> struct UnionFind {
    int fa[siz + 5];
    void inline init() {memset(fa, -1, sizeof(fa));}
    UnionFind() {init();}
    int inline root(int x) {return fa[x] < 0 ? x : fa[x] = root(fa[x]);}
    bool inline conn(int a, int b) {
        a = root(a); b = root(b);
        if(a == b) return 0;
        // if(fa[a] < fa[b]) swap(a, b);
        return fa[b] += fa[a], fa[a] = b, 1;
    }
};

template<typename num> struct Lissan {
    vector<num> lss; bool built;
    void inline clear() {lss.clear(); built = 0;}
    void inline add(num x) {lss.pub(x);}
    void inline build() {sort(all(lss)); lss.erase(unique(all(lss)), lss.end()); built = 1;}
    int inline size() {assert(built); return SZ(lss);} // Don't forget to build before querying.
    int inline get(num x, int th = 0) {assert(built); return lower_bound(all(lss), x) - lss.begin() + th;}
};

UnionFind<1 << 17> uf;
int n, m;
Lissan<int> lss;
int mode[1 << 17], x[1 << 17], y[1 << 17];
int id, nx[1 << 17], ny[1 << 17];
vector<int> vi[1 << 19];

void inline add(int l, int r, int x, int now = 1, int nl = 0, int nr = m) {
    if(nl >= l && nr <= r) return void(vi[now].pub(x));
    if(nl > r || nr < l) return;
    int m = (nl + nr) >> 1;
    add(l, r, x, now << 1, nl, m);
    add(l, r, x, now << 1 | 1, m + 1, nr);
}

void inline conn(int to, int x, int now = 1, int nl = 0, int nr = m) {
    while(SZ(vi[now])) {
        int y = uf.root(vi[now].back());
        nx[x] = min(nx[x], nx[y]);
        ny[x] = max(ny[x], ny[y]);
        uf.conn(y, x);
        vi[now].pob();
    }
    if(nl == nr) return;
    int m = (nl + nr) >> 1;
    if(m >= to) conn(to, x, now << 1, nl, m);
    else conn(to, x, now << 1 | 1, m + 1, nr);
}

int main() {
    scanf("%d", &n);
    cont(i, n) {
        scanf("%d%d%d", mode + i, x + i, y + i);
        lss.add(x[i]); lss.add(y[i]);
    }
    lss.build(); m = SZ(lss); uf.init();
    cont(i, n) if(mode[i] == 1) x[i] = lss.get(x[i]), y[i] = lss.get(y[i]);
    cont(i, n) {
        if(mode[i] == 1) {
            nx[++id] = x[i], ny[id] = y[i];
            conn(x[i], id); conn(y[i], id);
            if(nx[id] < ny[id] - 1) add(nx[id] + 1, ny[id] - 1, id);
        } else {
            int ix = uf.root(x[i]), iy = uf.root(y[i]);
            if(ix == iy || (nx[iy] < nx[ix] && nx[ix] < ny[iy]) || (nx[iy] < ny[ix] && ny[ix] < ny[iy])) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}