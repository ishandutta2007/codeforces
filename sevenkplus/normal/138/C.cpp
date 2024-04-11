#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100010
#define M 10010
int n,m,x[N*2],y[N*2],a[M],c[M],p[M];double z[N*2];vector<int> A;
/*PII A[N*2],B[N*2];*/double f[M*4],g[M*4];
bool cmp(int x,int y){return a[x]<a[y];}
void add(int p,int l,int r,int L,int R,double w)
{
    if(L<=l&&r<=R){f[p]*=w,g[p]*=w;return;}
    f[p*2+1]*=g[p],g[p*2+1]*=g[p],
    f[p*2+2]*=g[p],g[p*2+2]*=g[p],g[p]=1;
    int m=(l+r)/2;
    if(L<m)add(p*2+1,l,m,L,R,w);
    if(m<R)add(p*2+2,m,r,L,R,w);
}
double ask(int p,int l,int r,int a)
{
    if(l==r-1)return f[p];
    f[p*2+1]*=g[p],g[p*2+1]*=g[p],
    f[p*2+2]*=g[p],g[p*2+2]*=g[p],g[p]=1;
    int m=(l+r)/2;
    if(a<m)return ask(p*2+1,l,m,a);
    else return ask(p*2+2,m,r,a);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int X,Y,L,R;
        scanf("%d%d%d%d",&X,&Y,&L,&R);
        x[i*2]=X-Y,y[i*2]=X-1,z[i*2]=1-(double)L/100;
        x[i*2+1]=X+1,y[i*2+1]=X+Y,z[i*2+1]=1-(double)R/100;
    }
    for(int i=0;i<m;i++)scanf("%d%d",a+i,c+i),p[i]=i;
    sort(p,p+m,cmp);
    for(int i=0;i<m;i++)A.pb(a[i]);
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(),A.end()),A.end());
    for(int i=0;i<m*4;i++)f[i]=g[i]=1;
    for(int i=0;i<n*2;i++)
    {
        int l=lower_bound(A.begin(),A.end(),x[i])-A.begin(),r=lower_bound(A.begin(),A.end(),y[i]+1)-A.begin();
        if(l==r)continue;
        add(0,0,m,l,r,z[i]);
    }
    double S=0;
    for(int i=0;i<m;i++)
    {
        int w=lower_bound(A.begin(),A.end(),a[i])-A.begin();
        S+=ask(0,0,m,w)*c[i];
    }
    printf("%.9lf\n",S);
/*
    for(int i=0;i<n*2;i++)A[i]=mp(x[i],i),B[i]=mp(y[i]+1,i);
    sort(A,A+n*2),sort(B,B+n*2);
    double S=0,T=1,T2=1;
    int LA=0,LB=0,TA=0;
    for(int i=0;i<m;i++)
    {
        for(;LA<n*2&&A[LA].fi<=a[p[i]];LA++)
            if(z[A[LA].se]<1e-8)TA++;else T*=z[A[LA].se];
        for(;LB<n*2&&B[LB].fi<=a[p[i]];LB++)
            if(z[B[LB].se]<1e-8)TA--;else T2*=z[B[LB].se];
        if(!TA)S+=T*c[p[i]]/T2;
    }
    printf("%.9lf\n",S);
*/
    return 0;
}