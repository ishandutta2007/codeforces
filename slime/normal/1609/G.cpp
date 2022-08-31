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
// b,c a,c a,b
struct ST {
    ST *ch[2];
    int l, r;
    ll mx, lz, sm, psm; // psm: place * sum
}p[maxn << 1], *root;
int stcnt = 0;
ll x[maxn];
void upd(ST *a) {
    a->mx = max(a->ch[0]->mx, a->ch[1]->mx);
    a->sm = a->ch[0]->sm + a->ch[1]->sm;
    a->psm = a->ch[0]->psm + a->ch[1]->psm;
}
ll gsm(int l, int r) {
    return 1ll * (r + l) * (r - l + 1) / 2;
}
void bdtree(ST *a, int l, int r) {
    a->l = l, a->r = r, a->lz = 0;
    if (l == r) {
        a->mx = x[l], a->sm = x[l], a->psm = 1ll * l * x[l];
        return ;
    }
    int mid = (l + r) >> 1;
    a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
    bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
    upd(a);
}
void actlz(ST *a, ll cur) {
    a->mx += cur;
    a->lz += cur;
    a->sm += cur * (a->r - a->l + 1);
    a->psm += cur * gsm(a->l, a->r);
}
void pushdown(ST *a) {
    if (a->lz) {
        for (int i = 0; i < 2; i++)
            actlz(a->ch[i], a->lz);
        a->lz = 0;
    }
}
void pushlz(ST *a, int l, int r, ll cur) {
    if (a->l == l && a->r == r) {
        actlz(a, cur);
        return ;
    }
    int mid = (a->l + a->r) >> 1;
    pushdown(a);
    if (r <= mid) pushlz(a->ch[0], l, r, cur);
    else if (l > mid) pushlz(a->ch[1], l, r, cur);
    else pushlz(a->ch[0], l, mid, cur), pushlz(a->ch[1], mid + 1, r, cur);
    upd(a);
}
int qpl(ST *a, ll r) { // first >= r
    if (r > a->mx) return a->r + 1;
    if (a->l == a->r) return a->l;
    pushdown(a);
    if (a->ch[0]->mx >= r) return qpl(a->ch[0], r);
    else return qpl(a->ch[1], r);
}
ll qsm(ST *a, int l, int r, int u, int v) {
    if (a->l == l && a->r == r)
        return u * a->psm + v * a->sm;
    int mid = (a->l + a->r) >> 1;
    pushdown(a);
    if (r <= mid) return qsm(a->ch[0], l, r, u, v);
    else if (l > mid) return qsm(a->ch[1], l, r, u, v);
    else return qsm(a->ch[0], l, mid, u, v) + qsm(a->ch[1], mid + 1, r, u, v);
}
ll a[maxn], b[maxn];
int n, m, q;
ll inc = 0;
ll cal() {
    ll nans = (n + m - 1) * (qsm(root, 1, 1, 0, 1) + a[1] + inc);
    //cout << nans << endl;
    int pl = 1;
    for (int i = 2; i <= n + 1; i++) {
        int cp = qpl(root, a[i]) - 1;
        if (cp > pl) {
            nans += qsm(root, pl + 1, cp, -1, n + m + 2 - i);
            pl = cp;
        }
        // walk: pl + 1 ~ cp
        if (i != n + 1) nans += (n + m - pl - (i - 1)) * a[i];
    }
    return nans;
}
int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%lld", &b[i]), x[i] = b[i] - b[i - 1];
    inc = x[1], x[1] = 0;
    root = &p[stcnt++];
    bdtree(root, 1, m);
    for (int i = n; i >= 1; i--) a[i] -= a[i - 1];
    a[n + 1] = 1e18;
    while (q--) {
        int t, k, d;
        scanf("%d%d%d", &t, &k, &d);
        if (t == 1) 
            for (int j = n - k + 1; j <= n; j++) a[j] += d;
        else pushlz(root, m - k + 1, m, d);
        ll ans = cal();
        printf("%lld\n", ans);
    }
    return (0-0); //<3
}
/*
5 6 7
4 9 22 118 226
7 94 238 395 565 738
2 1 95
1 4 54
1 2 5
1 2 87
2 5 62
*/