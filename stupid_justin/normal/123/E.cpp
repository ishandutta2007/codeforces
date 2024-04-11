#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=1e5+5;
const int M=3e5+5;
int n;
int cnt,head[M],nxt[M],to[N];
int siz[N];
double sum[N];
double ans;
pair<double,double> P[N];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void add(int u,int v)
{
	nxt[++cnt]=to[u];
    head[cnt]=v;
    to[u]=cnt;
}
void dfs(int x,int fa)
{
    siz[x]=1,sum[x]=P[x].fi;
    double tmp=0;
    for (int i=to[x];i;i=nxt[i])
    {
        int to=head[i];
        if(to==fa) continue;
        dfs(to,x);
        siz[x]+=siz[to];
        sum[x]+=sum[to];
        tmp+=sum[to]*siz[to];
    }
    tmp+=(1-sum[x])*(n-siz[x]);
    ans+=tmp*P[x].se;
}

int main()
{
    int i;
    cin>>n;
    for (int i=1;i<n;++i)
    {
		int u,v;
        u=read();
		v=read();
        add(u,v);add(v,u);
    }
    pair<double,double> tot=mp(0,0);
    for (int i=1;i<=n;++i)
    {
		scanf("%lf%lf",&P[i].fi,&P[i].se);
        tot.fi+=P[i].fi;
		tot.se+=P[i].se;
    }
    for (int i=1;i<=n;++i)
        P[i].fi/=tot.fi,P[i].se/=tot.se;
	dfs(1,0);
	printf("%.12lf\n",ans);
    return 0;
}