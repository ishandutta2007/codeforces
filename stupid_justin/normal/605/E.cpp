#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=1005;
const int mod=924844033;
const int maxn=10005;
const int inf=0x3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
inline int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
inline int INV(int x){return ksm(x,mod-2);}
double p[N][N];
bool vis[N];
int n,last,nxt;
double E[N],sum[N],st[N];
signed main()
{
	rd(n);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {rd(p[i][j]);p[i][j]/=100;}
	for (int i=1;i<=n;i++) sum[i]=st[i]=1;
	vis[n]=1;E[0]=1e18;last=n;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (vis[j]) continue;
			sum[j]+=E[last]*p[j][last]*st[j];
			st[j]*=(1-p[j][last]);
			E[j]=sum[j]/(1-st[j]);
		}
		nxt=0;
		for (int j=1;j<=n;j++) if (!vis[j] && E[j]<E[nxt]) nxt=j;
		vis[nxt]=1;last=nxt;
	}
	printf("%.15lf\n",E[1]);
}