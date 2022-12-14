#include <bits/stdc++.h>
using namespace std;
typedef long long ftype;
typedef complex<ftype> point;
#define inf 1e18
struct LiChao_max
{
    struct line
    {
        long long a, b;
        line() { a = 0; b = 0; }
        line(long long _a, long long _b) { a = _a; b = _b; }
        int64_t eval(long long x) { return a * 1ll * x + (int64_t)b; }
    };

    struct node
    {
        node *l, *r; line f;

        node() { f = line(); l = nullptr; r = nullptr; }
        node(long long a, long long b) { f = line(a, b); l = nullptr; r = nullptr; }
        node(line v) { f = v; l = nullptr; r = nullptr; }
    };

    typedef node* pnode;

    pnode root; long long sz;
    void init(long long _sz) { sz = _sz + 1; root = nullptr; }

    void add_line(long long a, long long b) { line v = line(a, b); insert(v, -sz, sz, root); }
    int64_t query(long long x) { return query(x, -sz, sz, root); }

    void insert(line &v, long long l, long long r, pnode &nd)
    {
        if(!nd) { nd = new node(v); return; }

        int64_t trl = nd->f.eval(l), trr = nd->f.eval(r);
        int64_t vl = v.eval(l), vr = v.eval(r);

        if(trl >= vl && trr >= vr) return;
        if(trl < vl && trr < vr) { nd->f = v; return; }

        long long mid = (l + r) >> 1;
        if(trl < vl) swap(nd->f, v);
        if(nd->f.eval(mid) > v.eval(mid)) insert(v, mid + 1, r, nd->r);
        else swap(nd->f, v), insert(v, l, mid, nd->l);
    }

    int64_t query(long long x, long long l, long long r, pnode &nd)
    {
        if(!nd) return -inf;
        if(l == r) return nd->f.eval(x);

        long long mid = (l + r) >> 1;
        if(mid >= x) return max(nd->f.eval(x), query(x, l, mid, nd->l));
        return max(nd->f.eval(x), query(x, mid + 1, r, nd->r));
    }
};
long long dp[2000000];
long long a[2000000];
long long s[2000000];
long long pre[2000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long mx=0;
    for (int i=1;i<=n;i++)
        cin>>a[i],s[i]=s[i-1]+i*a[i],pre[i]=pre[i-1]+a[i],mx=max(mx,abs(pre[i]));
    LiChao_max tree;
    tree.init(mx+1);
    tree.add_line(0,0);
    long long ret=0;
    for (int i=1;i<=n;i++)
    {
        dp[i]=tree.query(pre[i])+s[i];
        ret=max(ret,dp[i]);
        tree.add_line(-i,-s[i]+pre[i]*i);
    }
    cout<<ret<<endl;
}