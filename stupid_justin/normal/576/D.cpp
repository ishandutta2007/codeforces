#include<bits/stdc++.h>
#define int long long
#define B bitset<N>
#define rd(x) x=read()
#define seg(x,y) (seg){x,y}
using namespace std;
const int N=155;
const int inf=0x3f3f3f3f;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
 
int n,m,ans=inf;
struct Edge
{
	int u,v,w;
	void input(){rd(u);rd(v);rd(w);}
	bool operator< (const Edge &o) const {return w<o.w;}
}E[N];
int d[N];
B b;
struct M {B a[N];}Mt;
inline B operator*(B x,M y){B ret;for (int i=0;i<=n;i++) ret[i]=(x&y.a[i]).any();return ret;}
inline M operator*(M x,M y){M ret;for (int i=0;i<n;i++) for (int j=0;j<n;j++)if (x.a[i][j]) ret.a[i]|=y.a[j];return ret;}
void ksm(M x,int y,B &z){while (y){if (y&1) z=z*x;x=x*x;y>>=1;}}
signed main()
{
	
	rd(n);rd(m);
	for (int i=1;i<=m;i++) {rd(E[i].u);E[i].u--;rd(E[i].v);E[i].v--;rd(E[i].w);}
	sort(E+1,E+m+1);
	b[0]=1;
	for (int i=1,t=0;i<=m;i++)
	{
		if (E[i].w>=ans) break;
		int o=E[i].w-t;
		ksm(Mt,o,b);
		Mt.a[E[i].v][E[i].u]=1;
		t=E[i].w;
		queue<int> Q;
		for (int u=0;u<n;u++) if (b[u]) Q.push(u),d[u]=0; else d[u]=inf;
		while (!Q.empty())
		{
			int u=Q.front();Q.pop();
			for (int v=0;v<n;v++) if (Mt.a[v][u] && d[v]==inf) d[v]=d[u]+1,Q.push(v);
		}
		ans=min(ans,t+d[n-1]);
	}
	if (ans==inf) puts("Impossible");
	else cout<<ans<<endl;
}