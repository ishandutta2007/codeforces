#include <bits/stdc++.h>
using namespace std;
struct LiChaoTree
{
    typedef long long ftype;
    typedef complex<ftype> point;
    #define MX 1e18
    #define MAX_QUERY 1e9
    #define MIN_QUERY 0
    #define x real
    #define y imag
    ftype dot(point a, point b) { return (conj(a) * b).x(); }
    ftype f(point a,  ftype x) { return dot(a, {x, 1}); }
    struct node
    {
        point line;
        node* L = NULL;
        node* R = NULL;
        node(){}
        node(point l) { line = l; }
    };
    node *root;
    void init() { root = NULL; }
    void add_line(ftype m,ftype c)
    {
        Insert(point(m,c),root,MIN_QUERY,MAX_QUERY);
    }
    ftype query(ftype x)
    {
        return Get(x,root,MIN_QUERY,MAX_QUERY);
    }
    void Insert(point nw, node* &v, ftype l, ftype r)
    {
        if (v==NULL) {
                v = new node(nw);
                return;
        }
        ftype m = (l + r) / 2;
        bool lef = f(nw, l) < f(v->line, l);
        bool right = f(nw, r) < f(v->line, r);

        if (lef && right)
            v->line = nw;
        if (lef == right)
            return;
        bool mid = f(nw, m) < f(v->line, m);
        if(lef!=mid)
        {
            if (right) swap(v->line,nw);
            Insert(nw, v->L, l, m);
        }
        else
        {
            if (left) swap(v->line,nw);
            Insert(nw, v->R, m+1, r);
        }
    }
    ftype Get(ftype x, node *v, ftype l, ftype r)
    {
        if (v==NULL)
            return MX;
        ftype m = (l + r) / 2;
        if(x <= m)
            return min(f(v->line, x), Get(x, v->L, l, m));
        else
            return min(f(v->line, x), Get(x, v->R, m+1, r));
    }
};

long long dp[2000000];
pair<long long,pair<long long,long long > > a[2000000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&a[i].first,&a[i].second.first,&a[i].second.second);
    sort(a+1,a+n+1);
    dp[0]=0;
    LiChaoTree tree;
    tree.init();
    tree.add_line(0,-dp[0]);
    long long ret=0;
    for (int i=1;i<=n;i++)
    {
        dp[i]=-tree.query(a[i].second.first)+a[i].second.first*a[i].first-a[i].second.second;
        tree.add_line(a[i].first,-dp[i]);
        ret=max(ret,dp[i]);
    }
    cout<<ret<<endl;
}