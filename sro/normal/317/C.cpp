/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
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

int n, v, e;
vector<int> nei[333];
int a[333], b[333];
bool lgl[333];
int fa[333];

int dfs(int now) {
    lgl[now] = 1;
    if(a[now] < b[now]) return now;
    loop(i, SZ(nei[now])) {
        int to = nei[now][i];
        if(lgl[to]) continue;
        fa[to] = now;
        int v = dfs(to);
        if(v) return v;
    }
    return 0;
}

struct Oper {
    int u, v, w;
    Oper(int u, int v, int w): u(u), v(v), w(w) {}
};

vector<Oper> res;

void inline make(int u, int v, int w) {
    res.pub(Oper(u, v, w));
    a[u] -= w; a[v] += w;
}

void trying(int s, int t, int f) {
    if(s == t) return;
    int u = fa[t];
    int r = a[u], fl = min(r, f);
    make(u, t, fl);
    trying(s, u, f);
    if(a[u] > r) make(u, t, a[u] - r);
}

int main() {
    scanf("%d%d%d", &n, &v, &e);
    cont(i, n) scanf("%d", a + i);
    cont(i, n) scanf("%d", b + i);
    cont(i, e) {
        int u, v; scanf("%d%d", &u, &v);
        nei[u].pub(v); nei[v].pub(u);
    }
    int mdf = 0;
    cont(i, n) if(a[i] != b[i]) ++mdf;
    while(mdf) {
        int sel = 0;
        cont(i, n) if(a[i] > b[i]) {
            sel = i; break;
        }
        if(!sel) return puts("NO"), 0;
        memset(lgl, 0, sizeof(lgl));
        int to = dfs(sel);
        if(!to) return puts("NO"), 0;
        int go = min(a[sel] - b[sel], b[to] - a[to]);
        trying(sel, to, go);
        mdf -= !(a[sel] - b[sel]);
        mdf -= !(a[to] - b[to]);
    }
    printf("%d\n", SZ(res));
    loop(i, SZ(res)) printf("%d %d %d\n", res[i].u, res[i].v, res[i].w);
    return 0;
}