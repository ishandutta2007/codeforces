#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
#define endl '\n'
using namespace std;
const int N=1e6+5;
const int M=317;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (ri i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (ri i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
int n;
struct Node
{
	int x,y;
}p[N];
double dis(Node a,Node b)
{
	int dx=a.x-b.x,dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}
bool cmp(Node a,Node b){return a.x==b.x?a.y>b.y:a.x<b.x;}
signed main()
{
	int T;rd(T);
	while (T--)
	{
		double ans=0;
		rd(n);
		for (int i=1;i<=2*n;i++) {rd(p[i].x);rd(p[i].y);p[i].x=abs(p[i].x);p[i].y=abs(p[i].y);}
		sort(p+1,p+2*n+1,cmp);
		for (int i=1;i<=n;i++) ans+=dis(p[i],p[2*n+1-i]);
		printf("%.10lf\n",ans);
	}
}