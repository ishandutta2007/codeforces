#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 100010
#define M 7
struct P{int x,y;P(){}P(int X,int Y):x(X),y(Y){}}a[N];
inline bool cmx(int x,int y){return a[x].x<a[y].x||a[x].x==a[y].x&&a[x].y<a[y].y;}
inline bool cmy(int x,int y){return a[x].y<a[y].y||a[x].y==a[y].y&&a[x].x<a[y].x;}
inline double sqr(double x){return x*x;}
inline double dis(int x,int y){return sqrt(sqr(a[x].x-a[y].x)+sqr(a[x].y-a[y].y));}
int n,A[N],B[N*20],Q[N],T,vx,vy;double S;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
PII ff(int l,int r)
{
    int s=r-l,mid=(l+r)/2;
    if(r-l<=M)
    {
        int T0=T;T+=s;
        for(int i=l;i<r;i++)B[T0+i-l]=A[i];
        sort(B+T0,B+T,cmy);
        for(int i=T0;i<T;i++)for(int j=i+1;j<T;j++)
            if(dis(B[i],B[j])<S)S=min(S,dis(B[i],B[j])),vx=B[i],vy=B[j];
        return mp(T0,T);
    }
    PII Lx=ff(l,mid),Rx=ff(mid,r);
    int T0=T;T+=s;
    merge(B+Lx.fi,B+Lx.se,B+Rx.fi,B+Rx.se,B+T0,cmy);
    int mx=a[A[mid]].x,L=0,R=-1;
    for(int i=T0;i<T;i++)
    {
        int u=B[i];if(abs(a[u].x-mx)>=S)continue;
        int by=a[u].y;while(L<=R&&abs(a[Q[L]].y-by)>=S)++L;
        for(int j=L;j<=R;j++)
            if(dis(u,Q[j])<S)S=min(S,dis(u,Q[j])),vx=u,vy=Q[j];
        Q[++R]=u;
    }
    return mp(T0,T);
}
int x[N],y[N],d[N];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",x+i,y+i);
        if(x[i]<0&&y[i]<0)d[i]=4;else
        if(x[i]<0&&y[i]>=0)d[i]=2;else
        if(x[i]>=0&&y[i]<0)d[i]=3;else
        if(x[i]>=0&&y[i]>=0)d[i]=1;
        x[i]=abs(x[i]),y[i]=abs(y[i]);
        a[i]=P(x[i],y[i]);
    }
    for(int i=0;i<n;i++)A[i]=i;sort(A,A+n,cmx);
    S=1e99,T=0,ff(0,n);
    printf("%d %d %d %d\n",vx+1,5-d[vx],vy+1,d[vy]);
    return 0;
}