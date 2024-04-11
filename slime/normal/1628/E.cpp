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
const int maxn = 300005;
const int h = 18;
int dep[maxn];
int fa[maxn][h + 1], mx[maxn][h + 1];
int lca(int a, int b) {
    if (a == -1 || b == -1) return a + b + 1;
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = h; i >= 0; i--) 
        if (dep[fa[a][i]] >= dep[b]) a = fa[a][i];
    for (int i = h; i >= 0; i--)
        if (fa[a][i] != fa[b][i])
            a = fa[a][i], b = fa[b][i];
    if (a != b) a = fa[a][0];
    return a;
}
pi qq(int a, int b) {
    if (a == -1 || b == -1) return mp(a + b + 1, 0);
    if (dep[a] < dep[b]) swap(a, b);
    int ans = 0;
    for (int i = h; i >= 0; i--) 
        if (dep[fa[a][i]] >= dep[b]) 
            chkmax(ans, mx[a][i]), 
            a = fa[a][i];
    for (int i = h; i >= 0; i--)
        if (fa[a][i] != fa[b][i])
            chkmax(ans, mx[a][i]), 
            chkmax(ans, mx[b][i]), 
            a = fa[a][i], 
            b = fa[b][i];
    if (a != b) 
        chkmax(ans, mx[a][0]), 
        chkmax(ans, mx[b][0]), 
        a = fa[a][0];
    return mp(a, ans);
}
struct ST {
    int l, r;
    ST *ch[2];
    int lz;
    pi cur;
    pi tot;
}p[maxn << 1], *root;
int stcnt = 0;
pi uni(pi a, pi b) {
    // lc, mx
    pi res;
    pi cr = qq(a.fi, b.fi);
    res.fi = cr.fi;
    res.se = max(a.se, b.se);
    chkmax(res.se, cr.se);
    return res;
}
void bdtree(ST *a, int l, int r) {
    a->lz = 0;
    a->cur = mp(-1, 0);
    a->l = l, a->r = r;
    if (l == r) {
        a->tot = mp(l, 0);
        return ;
    }
    a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
    int mid = (l + r) >> 1;
    bdtree(a->ch[0], l, mid);
    bdtree(a->ch[1], mid + 1, r);
    a->tot = uni(a->ch[0]->tot, a->ch[1]->tot);
}
void actlz(ST *a, int lz) {
    if (lz == -1) return ;
    a->lz = lz;
    if (lz == 1) 
        a->cur = a->tot;
    else a->cur = mp(-1, 0);
}
void pushdown(ST *a) {
    if (a->lz != -1) {
        for (int i = 0; i < 2; i++)
            actlz(a->ch[i], a->lz);
        a->lz = -1;
    }
}
void push(ST *a, int l, int r, int lz) {
    if (a->l == l && a->r == r) {
        actlz(a, lz);
        return ;
    }
    int mid = (a->l + a->r) >> 1;
    pushdown(a);
    if (r <= mid) push(a->ch[0], l, r, lz);
    else if (l > mid) push(a->ch[1], l, r, lz);
    else push(a->ch[0], l, mid, lz), 
        push(a->ch[1], mid + 1, r, lz);
    a->cur = uni(a->ch[0]->cur, a->ch[1]->cur);
}
 
vector<pi> eg[maxn];
void dfs(int a) {
    for (auto v : eg[a]) {
        int to = v.fi;
        if (dep[to]) continue;
        dep[to] = dep[a] + 1, fa[to][0] = a, mx[to][0] = v.se;
        for (int i = 1; i <= h; i++)
            fa[to][i] = fa[fa[to][i - 1]][i - 1], 
            mx[to][i] = max(mx[to][i - 1], mx[fa[to][i - 1]][i - 1]);
        dfs(to);
    }
}
char ch,B[1<<20],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<20,stdin),S==T)?0:*S++)
#define isd(c) (c>='0'&&c<='9')
int aa,bb;int F(){
    while(ch=getc(),!isd(ch)&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;
}
#define gi F()
#define BUFSIZE 5000000
namespace fob {char b[BUFSIZE]={},*f=b,*g=b+BUFSIZE-2;}
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
struct foce {~foce() {pob; fflush(stdout);}} _foce;
namespace ib {char b[100];}
inline void pint(int x)
{
    if(x==0) {pc(48); return;}
    if(x<0) {pc('-'); x=-x;} // 
    char *s=ib::b;
    while(x) *(++s)=x%10, x/=10;
    while(s!=ib::b) pc((*(s--))+48);
}
int main() {
    int n, q;
    n = gi, q = gi;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        u = gi, v = gi, w = gi;
        eg[u].pb(mp(v, w));
        eg[v].pb(mp(u, w));
    }
    dep[1] = 1;
    dfs(1);
    root = &p[stcnt++];
    bdtree(root, 1, n);
    for (int i = 1; i <= q; i++) {
        int tp, l, r;
        tp = gi, l = gi;
        if (tp <= 2) {
            r = gi;
            push(root, l, r, 2 - tp);
        }
        else {
            pi cr = root->cur;
            int ans = 0;
            if (cr.fi == -1) ans = -1;
            else {
                cr = uni(cr, mp(l, 0));
                ans = cr.se;
            }
            if (ans == 0) ans = -1;
            pint(ans), pc(10);
        }
    }
    return (0-0); //<3
}