#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,Ans,p,fa[MAXN],L[MAXN],R[MAXN],S[MAXN];
int A[MAXN][2][2];
struct node 
{
    int x,v,p;
}a[MAXN];
struct pa 
{
    int x,y,id,p,v;
}q[MAXN];
struct tree 
{
    int a[2][2];
    int v;
    inline void clear() 
    {
        for (int x=0;x<=1;x++)
        for (int y=0;y<=1;y++)
        a[x][y]=0;
        v=0;
    }
}f[MAXN*4],ans;
inline int quick(int x,int y) 
{
    int s=1;
    for (;y;y>>=1,x=1ll*x*x%MOD)
    if (y&1) s=1ll*s*x%MOD;
    return s;
}
inline void up(int o,int l,int r) 
{
    int mid=(l+r)>>1;
    f[o].clear();   
    for (int x=0;x<=1;x++)
    for (int y=0;y<=1;y++)
    for (int i=0;i<=1;i++)
    for (int j=0;j<=1;j++) 
    {
        if (A[mid][y][i]) continue;
        (f[o].a[x][j]+=(1ll*f[o*2].a[x][y]*f[o*2+1].a[i][j])%MOD)%=MOD;
    }
}
inline void build(int o,int l,int r) 
{
    if (l==r) 
    {
        f[o].a[0][0]=L[l];
        f[o].a[1][1]=R[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(o*2,l,mid);
    build(o*2+1,mid+1,r);
    up(o,l,r);
}
inline void change(int o,int l,int r,int ll) 
{
    if (l==r) return ;
    int mid=(l+r)>>1;
    if (ll<=mid) change(o*2,l,mid,ll);
    else change(o*2+1,mid+1,r,ll);
    up(o,l,r);
}
inline void ask(int o,int l,int r,int ll,int rr) 
{
    if (l==ll&&r==rr) 
    {
        if (!ans.v) ans=f[o];
        else 
        {
            tree tmp;
            tmp.clear();
            for (int x=0;x<=1;x++)
            for (int y=0;y<=1;y++)
            for (int i=0;i<=1;i++)
            for (int j=0;j<=1;j++) 
            {
                if (A[l-1][y][i]) continue;
                (tmp.a[x][j]+=(1ll*ans.a[x][y]*f[o].a[i][j])%MOD)%=MOD;
            }
            ans=tmp;
        }
        ans.v=1;
        return ;
    }
    int mid=(l+r)>>1;
    if (rr<=mid) ask(o*2,l,mid,ll,rr);
    else if (ll>mid) ask(o*2+1,mid+1,r,ll,rr);
    else 
    {
        ask(o*2,l,mid,ll,mid);
        ask(o*2+1,mid+1,r,mid+1,rr);
    }
}
bool cmp(pa x,pa y) 
{
    long long X=1ll*x.x*y.y;
    long long Y=1ll*x.y*y.x;
    return X<Y;
}
int main() 
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i].x,&a[i].v,&a[i].p);
    int r=0;
    for (int i=1;i<n;i++) 
    {
        q[++r].x=a[i+1].x-a[i].x;
        q[r].y=a[i+1].v+a[i].v;
        q[r].id=i;
        q[r].v=1;
        if (a[i+1].v==a[i].v) continue;
        if (a[i+1].v>a[i].v) 
        {
            q[++r].x=a[i+1].x-a[i].x;
            q[r].y=a[i+1].v-a[i].v;
            q[r].id=i;
            q[r].v=2;
            continue;
        }
        q[++r].x=a[i+1].x-a[i].x;
        q[r].y=-a[i+1].v+a[i].v;
        q[r].id=i;
        q[r].v=3;
    }
    sort(q+1,q+r+1,cmp);
    for (int i=1;i<=n;i++) 
    {
        L[i]=100-a[i].p,R[i]=a[i].p;
    }
    build(1,1,n);
    int Ans=0;
    for (int i=1;i<=r;i++) 
    {
        ans.clear();
        tree ans1;
        ask(1,1,n,1,q[i].id);
        ans1=ans;
        ans.clear();
        ask(1,1,n,q[i].id+1,n);
        if (q[i].v==1) 
        {
            int s0=0;
            for (int j=0;j<=1;j++) (s0+=ans1.a[j][1])%=MOD;
            int s1=0;
            for (int j=0;j<=1;j++) (s1+=ans.a[0][j])%=MOD;
            (Ans+=1ll*q[i].x*quick(q[i].y,MOD-2)%MOD*s0%MOD*s1%MOD)%=MOD;
            A[q[i].id][1][0]=1;
            change(1,1,n,q[i].id);
            continue;
        }
        if (q[i].v==2) 
        {
            int s0=0;
            for (int j=0;j<=1;j++) (s0+=ans1.a[j][0])%=MOD;
            int s1=0;
            for (int j=0;j<=1;j++) (s1+=ans.a[0][j])%=MOD;
            (Ans+=1ll*q[i].x*quick(q[i].y,MOD-2)%MOD*s0%MOD*s1%MOD)%=MOD;
            A[q[i].id][0][0]=1;
            change(1,1,n,q[i].id);
            continue;
        }
        if (q[i].v==3) 
        {
            int s0=0;
            for (int j=0;j<=1;j++) (s0+=ans1.a[j][1])%=MOD;
            int s1=0;
            for (int j=0;j<=1;j++) (s1+=ans.a[1][j])%=MOD;
            (Ans+=1ll*q[i].x*quick(q[i].y,MOD-2)%MOD*s0%MOD*s1%MOD)%=MOD;
            A[q[i].id][1][1]=1;
            change(1,1,n,q[i].id);
            continue;
        }
    }
    printf("%lld\n",1ll*Ans*quick(quick(100,n),MOD-2)%MOD);
}