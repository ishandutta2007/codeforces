#include <stdio.h>
inline int read(){int num=0,f=1;char c=getchar();while(c<48||c>57){if(c=='-')f=-1;c=getchar();}while(c>47&&c<58)num=num*10+(c^48),c=getchar();return num*f;}
struct Edge{int v,nxt;}e[600005];
typedef int arr[300005];
arr h,p,d;const int mod=1000000007;int cnt=1,fl;
inline void addedge(int u,int v){e[cnt]=(Edge){v,h[u]};h[u]=cnt++;}
void dfs(int u,int fa,int dep){d[u]=dep;int f=0;for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;if(v==fa&&f==0){f=1;continue;}if(d[v])fl=d[v]-d[u]+1;else dfs(v,u,dep+1);}}
signed main()
{
	int n=read(),cc=0;long long qwq=1;p[0]=1;for(int i=1;i<=n;i++){int x=read();addedge(i,x);addedge(x,i);p[i]=p[i-1]*2;p[i]%=mod;}
	for(int i=1;i<=n;i++)if(!d[i]){dfs(i,0,1);cc+=fl;(qwq*=(p[fl]-2))+=mod,qwq%=mod;}
	printf("%lld\n",p[n-cc]*qwq%mod);return 0;
}