//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<ll>
#define pi pair<ll, ll>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 100005;
const int N = 10000005;
map<int, int> uu;
mt19937 rd;
int gw(int x) {
    if (uu.count(x)) return uu[x];
    int cr = rd();
    uu[x] = cr; return cr;
}
int hs[maxn];

struct ST {
	int l, r;
	ST *ch[2];
    int sum;
}p[N], *root[maxn], *tw;
int stcnt = 0;
void upd(ST *a) {
    a->sum = 0;
    for (int i = 0; i < 2; i++)
        if (a->ch[i]) a->sum += a->ch[i]->sum;
}
void copy(ST *a, ST *b, int l, int r) {
    a->l = l, a->r = r;
    if (!b) {
        a->sum = 0;
        return ;
    }
}
void nc(ST *a, int tp) {
    if (a->ch[tp]) return ;
    ST *n1 = &p[stcnt++];
    int mid = (a->l + a->r) >> 1;
    if (tp == 0) copy(n1, a->ch[tp], a->l, mid);
    else copy(n1, a->ch[tp], mid + 1, a->r);
    a->ch[tp] = n1;
}
void ins(ST *a, int pl, int h) {
    a->sum += h;
    if (a->l == a->r) 
        return ;
    int t = 0;
    int mid = (a->l + a->r) >> 1;
    if (pl <= mid) t = 0;
    else t = 1;
    nc(a, t);
    ins(a->ch[t], pl, h);
}
ll qs(ST *a) {
    if (!a) return 0;
    return a->sum;
}
ll qts(ST *a, int tp) {
    if (!a) return 0;
    return qs(a->ch[tp]);
}
ST *gch(ST *a, int tp) {
    if (a) return a->ch[tp];
    else return NULL;
}
int fd(ST *a, ST *b, ST *c, int pl, int dc) {
    // find a - b - c - dc first
    if (!a) return -1;
    if (pl < a->l || pl > a->r) dc = 0;
    if (qs(a) - qs(b) - qs(c) - dc == 0) return -1;
    if (a->l == a->r) return a->l;
    if (a->ch[0]) {
        int cr = fd(gch(a, 0), gch(b, 0), gch(c, 0), pl, dc);
        if (cr != -1) return cr;
    } 
    return fd(gch(a, 1), gch(b, 1), gch(c, 1), pl, dc);
}
map<int, int> ww[maxn];
#define ar3 array<int, 3>
set<ar3> tot;
set<pi> wss[maxn]; 
ll qans() {
    ar3 ff = (*tot.begin());
    int u = ff[1], v = ff[2], w = ff[0];
    ll res = 10ll * mod;
    ll ans = fd(tw, root[u], root[v], w, -gw(w));
    if (ans != -1 && ans < res) res = ans; 
    vector<pi> h[2];
    int g[2] = {u, v};
    for (int m = 0; m < 2; m++) {
        for (auto s : wss[g[m]]) {
            if (s.se == g[0] + g[1] - g[m]) continue;
            h[m].pb(s);
            if (h[m].size() >= 2) break;
        }
        if (h[m].size() >= 2) chkmin(res, h[m][0].fi + h[m][1].fi);
    }
    if (h[0].size() && h[1].size())
        chkmin(res, (ll)h[0][0].fi + h[1][0].fi + w);
    ans = res + w;
    for (int i = 0; i < h[0].size(); i++)
        for (int j = 0; j < h[1].size(); j++)
            if (h[0][i].se != h[1][j].se)
                chkmin(ans, (ll)h[0][i].fi + h[1][j].fi);
    return ans;
}
void adewei(int u, int v, int w, int tp) {
    int cur = gw(w);
    cur *= tp;
    ins(tw, w, cur);
    ins(root[u], w, cur);
    ins(root[v], w, cur);
}
void ade(int u, int v, int w) {
    if (u > v) swap(u, v);
    adewei(u, v, w, 1);
    ww[u][v] = ww[v][u] = w;
    tot.insert((ar3){w, u, v});
    wss[u].insert(mp(w, v)), wss[v].insert(mp(w, u));
}
void deg(int u, int v) {
    if (u > v) swap(u, v);
    int nw = ww[u][v];
    adewei(u, v, nw, -1);
    tot.erase((ar3){nw, u, v});
    wss[u].erase(mp(nw, v)), wss[v].erase(mp(nw, u));
}
int main() {
    int n, m;
    cin >> n >> m;
    const int inf = mod;
    tw = &p[stcnt++], tw->l = 1, tw->r = inf;
    for (int i = 1; i <= n; i++)
        root[i] = &p[stcnt++], root[i]->l = 1, root[i]->r = mod;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        ade(u, v, w);
    }  
    printf("%lld\n", qans());
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int t, u, v, w;
        scanf("%d%d%d", &t, &u, &v);
        if (t == 0) deg(u, v);
        else scanf("%d", &w), ade(u, v, w);
        printf("%lld\n", qans());
    }
    return (0-0); //<3
}