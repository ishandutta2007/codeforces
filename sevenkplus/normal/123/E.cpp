#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define N 100010
int n,q[N],fa[N];double c[N],d[N],f0[N],f[N],g[N],gu[N],S=0;vector<int> A[N];
int main()
{
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),A[x].pb(y),A[y].pb(x);
    double Sc=0,Sd=0;
    for(int i=1;i<=n;i++)scanf("%lf %lf",c+i,d+i),Sc+=c[i],Sd+=d[i];
    for(int i=1;i<=n;i++)c[i]/=Sc,d[i]/=Sd;
    q[1]=1;
    for(int L=1,R=1;L<=R;)
    {
        int x=q[L++];
        for(vector<int>::iterator i=A[x].begin();i!=A[x].end();i++)
            if(*i!=fa[x])q[++R]=*i,fa[*i]=x;
    }
    for(int i=n;i>=1;i--)
    {
        int x=q[i];f0[x]=1,f[x]=c[x];
        for(vector<int>::iterator i=A[x].begin();i!=A[x].end();i++)
            if(*i!=fa[x])f0[x]+=f0[*i],f[x]+=f[*i],g[x]+=g[*i]+f[*i];
    }
    for(int i=2;i<=n;i++)
    {
        int x=q[i],y=fa[x];
        gu[x]=gu[y]+g[y]-g[x]-f[x]+1-f[x];
    }
    //for(int i=1;i<=n;i++)printf("%.3lf %.3lf %.3lf %.3lf\n",f0[i],f[i],g[i],gu[i]);
    for(int i=1;i<=n;i++)
    {
        int x=i;double T=0;;
        for(vector<int>::iterator i=A[x].begin();i!=A[x].end();i++)
            if(*i!=fa[x])T+=f0[*i]*f[*i];
        if(x!=1)
            T+=(1-f[x])*(n-f0[x]);
        S+=T*d[x];
    }
    printf("%.18lf\n",S);
    return 0;
}