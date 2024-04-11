#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1e18
#define MOD 1000000007
#define F first
#define S second
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,k;
double a[MAXN];
double x,y;
//0: 0  1: 1/(x+y) 2: 1/y
//valid: (0,any) (1,1) 
struct mat
{
    double a[3][3];
    void construct(double r)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i+j>2) a[i][j]=-INF; else a[i][j]=(j==0?0:1.0*r/(j==1?x+y:y));
    }
};
mat operator+(const mat &x,const mat &y)
{
    mat z;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            z.a[i][j]=-INF;
        for(int k=0;k<3;k++)
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    z.a[i][j]=max(z.a[i][j],x.a[i][k]+y.a[k][j]);
    return z;
};
struct segtree
{
    mat t[4*MAXN];
    void pushup(int k)
    {
        t[k]=t[k*2]+t[k*2+1];
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            t[k].construct(a[l]);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,double val)
    {
        if(l==r)
        {
            t[k].construct(val);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,val); else update(k*2+1,mid+1,r,pos,val);
        pushup(k);
    }
    mat query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) 
        {
            mat tmp;
            tmp.construct(0.0);
            return tmp;
        }
        if(l>=x&&r<=y) return t[k];
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%Lf%Lf",&x,&y);
    if(x>y) swap(x,y);
    a[0]=0.0;
    for(int i=1;i<=n;i++) scanf("%Lf",&a[i]);
    seg.build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int type,l,r;
        scanf("%d%d%d",&type,&l,&r);
        if(type==1)
            seg.update(1,1,n,l,r);
        else
        {
            mat tmp=seg.query(1,1,n,l,r);
            mat tmp2; tmp2.construct(0); tmp2=tmp+tmp2;
            printf("%.15Lf\n",tmp2.a[0][0]);
        }
    }
    return 0;
}