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
#define db double
const int maxn = 200005;
struct info {
    db x[3][3]; //  
    info(){for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) x[i][j] = 0;}
};
int x, y;
info uni(info a, info b) {
    info res;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 3; l++) {
                    if (k >= 2 || l >= 2)
                        if (k && l) continue;
                    chkmax(res.x[i][j], a.x[i][k] + b.x[l][j]);
                }
        }
    return res;
}
struct ST {
    int l, r;
    ST *ch[2];
    info res;
}p[maxn << 2], *root;
db b[maxn];
info gg(db a) {
    info res;
    res.x[0][0] = 0;
    res.x[1][1] = a / (x + y);
    res.x[2][2] = a / y;
    return res;
}
void upd(ST *a) {
    a->res = uni(a->ch[0]->res, a->ch[1]->res);
}
int stcnt = 0;
void bdtree(ST *a, int l, int r) {
    a->l = l, a->r = r;
    if (l == r) {
        a->res = gg(b[l]);
        return ;
    }
    int mid = (l + r) >> 1;
    a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
    bdtree(a->ch[0], l, mid), 
    bdtree(a->ch[1], mid + 1, r);
    upd(a);
}
void add(ST *a, int pl, db cur) { // zhu xi shu jia
    if (a->l == a->r) {
        a->res = gg(cur);
        return ;
    }
    int mid = (a->l + a->r) >> 1;
    if (pl <= mid) add(a->ch[0], pl, cur);
    else add(a->ch[1], pl, cur);
    upd(a);
}
info qsum(ST *a, int l, int r) {
    if (a->l == l && a->r == r)
        return a->res;
    int mid = (a->l + a->r) >> 1;
    if (r <= mid) return qsum(a->ch[0], l, r);
    else if (l > mid) return qsum(a->ch[1], l, r);
    else return uni(qsum(a->ch[0], l, mid),qsum(a->ch[1], mid + 1, r));
}
int main() {
    int n, q;
    cin >> n >> q;
    cin >> x >> y;
    if (x > y)
        swap(x, y);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    root = &p[stcnt++];
    bdtree(root, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int t, k, v;
        scanf("%d%d%d", &t, &k, &v);
        if (t == 1) {
            add(root, k, v);
        }
        else
        {
            info cur = qsum(root, k, v);
            db ans =0 ;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    chkmax(ans, cur.x[i][j]);
            printf("%.10lf\n", ans);
        }
    }
    return (0-0); //<3
}