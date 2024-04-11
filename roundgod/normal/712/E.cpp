#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<double,double> P;
int n,q;
double p[MAXN];
P merge(P p,P q)
{
    if(p.F==-1.0) return q;
    if(q.F==-1.0) return p;
    double a=p.F,b=p.S,c=q.F,d=q.S;
    return P(a*c/(1-b+b*c),d+(1-d)*b*c/(1-b+b*c));
}
struct segtree
{
    P res[4*MAXN];
    void pushup(int k)
    {
        res[k]=merge(res[k*2],res[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            res[k]=P(p[l],p[l]);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int p,double v)
    {
        if(l==r)
        {
            res[k]=P(v,v);
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,v); else update(k*2+1,mid+1,r,p,v);
        pushup(k);
    }
    P query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return P(-1.0,-1.0);
        if(l>=x&&r<=y) return res[k];
        int mid=(l+r)/2;
        return merge(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        p[i]=(double)a/b;
    }
    seg.build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int type,l,r,a,b,x;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d%d",&x,&a,&b);
            double pp=(double)a/b;
            seg.update(1,1,n,x,pp);
        }
        else
        {
            scanf("%d%d",&l,&r);
            P ret=seg.query(1,1,n,l,r);
            printf("%.10f\n",ret.F);
        }
    }
    return 0;
}