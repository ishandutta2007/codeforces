#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 100005
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int N = 20000005;
struct ST {
    int l, r;
    ST *ch[2];
    int mn;
}p[N];
int stcnt = 0;
void ins(ST *a, int pl, int id) {
    chkmin(a->mn, id);
    if (a->l == a->r) return ;
    int mid = (a->l + a->r) >> 1;
    int tp = 0;
    if (pl <= mid) tp = 0;
    else tp = 1;
    if (!a->ch[tp]) {
        a->ch[tp] = &p[stcnt++];
        a->ch[tp]->mn = 1e9;
        a->ch[tp]->ch[0] = a->ch[tp]->ch[1] = NULL;
        if (tp == 0) a->ch[tp]->l = a->l, a->ch[tp]->r = mid;
        else a->ch[tp]->l = mid + 1, a->ch[tp]->r = a->r;
    }
    ins(a->ch[tp], pl, id);
}
int q(ST *a, int l, int r) {
    if (!a) return 1e9;
    if (a->l == l && a->r == r)
        return a->mn;
    int mid = (a->l + a->r) >> 1;
    if (r <= mid) return q(a->ch[0], l, r);
    else if (l > mid) return q(a->ch[1], l, r);
    else return min(q(a->ch[0], l, mid), q(a->ch[1], mid + 1, r));
}
ST *d[maxn];
int n;
int lb(int x) {
    return x & -x;
}
void ins(int l, int r, int id) {
    while (r <= n) {
        ins(d[r], l, id);
        r += lb(r);
    }
}
int q(int l, int r) {
    int ans = 1e9;
    while (r) {
        chkmin(ans, q(d[r], l, n));
        r -= lb(r);
    }
    return ans;
}
int rg[maxn][2];
int gt(int l, int r) {
    if (l > r) return 0;
    int p = q(l, r);
    if (p > maxn) return 0;
    int ans = rg[p][1] - rg[p][0] + 1 + gt(l, rg[p][0] - 1) + gt(rg[p][1] + 1, r);
    return ans;
}
int ans[maxn];
int main() {
    int m;
    cin >> n >> m;
    vector<pi> cr;
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &rg[i][0], &rg[i][1]), 
        cr.pb(mp(rg[i][1] - rg[i][0] + 1, i));
    sort(cr.begin(), cr.end());
    for (int i = 1; i <= n; i++) {
        d[i] = &p[stcnt++];
        d[i]->mn = 1e9;
        d[i]->l = 1, d[i]->r = n;
    }
    int pl = m - 1;
    for (int i = n; i >= 1; i--) {
        while (pl >= 0 && cr[pl].fi >= i) {
            int id = cr[pl].se;
            ins(rg[id][0], rg[id][1], id);
            pl--;
        }
        ans[i] = gt(1, n);
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
/*
6 5
2 3
3 5
1 1
1 5
1 6
*/