//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 500005;

struct ST
{
    int l, r;
    ST *ch[2];
    int lz;
    int mn, mpl;
} stp[maxn << 2], *root;
void upd(ST *a)
{
    a->mn = min(a->ch[0]->mn, a->ch[1]->mn);
    if (a->mn == a->ch[0]->mn) a->mpl = a->ch[0]->mpl;
    else a->mpl = a->ch[1]->mpl;
}
inline void actlz(ST *a, int lz) {
    a->lz += lz;
    a->mn += lz;
}
void pushdown(ST *a) {
    for (int i = 0; i < 2; i++)
        actlz(a->ch[i], a->lz);
    a->lz = 0;
}
int stcnt = 0;
void bdtree(ST *a, int l, int r)
{
    a->l = l, a->r = r, a->lz = a->mn = 0, a->mpl = l;
    if (l == r)
        return;
    int mid = (a->l + a->r) >> 1;
    a->ch[0] = &stp[stcnt++];
    a->ch[1] = &stp[stcnt++];
    bdtree(a->ch[0], l, mid);
    bdtree(a->ch[1], mid + 1, r);
    upd(a);
}
void push(ST *a, int l, int r, int lz)
{
    if (a->l == l && a->r == r) {
        actlz(a, lz);
        return;
    }
    pushdown(a);
    int mid = (a->l + a->r) >> 1;
    if (r <= mid)
        push(a->ch[0], l, r, lz);
    else if (l > mid)
        push(a->ch[1], l, r, lz);
    else {
        push(a->ch[0], l, mid, lz);
        push(a->ch[1], mid + 1, r, lz);
    }
    upd(a);
}
pi qr(ST *a, int l, int r) {
    if (a->l == l && a->r == r)
        return mp(a->mn, a->mpl);
    pushdown(a);
    int mid = (a->l + a->r) >> 1;
    if (r <= mid)
        return qr(a->ch[0], l, r);
    else if (l > mid)
        return qr(a->ch[1], l, r);
    else
        return min(qr(a->ch[0], l, mid), qr(a->ch[1], mid + 1, r));
}
int p[maxn], q[maxn]; // q : place of each

int n, m;
int md;
int fl[maxn]; // 
int totfl[2] = {0, 0};
int chk(int a, int b, int c) {
    int r = (q[b] - q[a] + n) % n;
    int g = (q[c] - q[a] + n) % n;
    return r < g;
}
vi ch[maxn];
int ttp[maxn];
vi ids[maxn]; // check
int ccnt = 0;
void push(int a, int b, int c, int tp) {
    ccnt += 1;
    ttp[ccnt] = tp;
    ch[ccnt] = {a, b, c};
    for (auto v : ch[ccnt])
        ids[v].pb(ccnt);
}
void rec(int id) {
    int tp = ttp[id];
    totfl[tp] -= fl[id];
    fl[id] = 1 ^ chk(ch[id][0], ch[id][1], ch[id][2]);
    totfl[tp] += fl[id];
}
void upd(int id, int tp) {
    if (p[id] == md) return ;
    if (p[id] > md) push(root, id, n, tp);
    else push(root, id, n, -tp);
}
void up1(int id) {
    for (auto v : ids[id])
        rec(v);
}
int cal() {
    int pl = q[md];
    pi cans = qr(root, 1, n); pi cc = qr(root, pl, pl);
    if (cans.fi < cc.fi) return cans.se;
    if (totfl[0]) return pl;
    if (totfl[1]) return pl - 1;
    return -1;
}
int main() {
    cin >> n >> m;
    n = 2 * n + 1;
    root = &stp[stcnt++]; bdtree(root, 1, n);
    md = (n + 1) / 2;
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]), q[p[i]] = i;
    for (int i = 1; i <= md - 3; i++)
        push(i, i + 1, i + 2, 0);
    push(md, 1, 2, 0);
    for (int i = md; i <= n - 2; i++)
        push(i, i + 1, i + 2, 1);
    
    for (int i = 1; i <= n; i++)
        upd(i, 1), up1(i);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        upd(u, -1);
        upd(v, -1);
        swap(p[u], p[v]);
        int x = p[u], y = p[v]; swap(q[x], q[y]);
        up1(x); up1(y);
        upd(u, 1), upd(v, 1);
        int ans = cal();
        if (ans == n) ans = 0;
        printf("%d\n", ans);
    }
    return (0-0); //<3
}