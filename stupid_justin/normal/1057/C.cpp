#include<bits/stdc++.h>
#define int long long 
#define rd(x) x=read()
#define mid (l+r>>1)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define LS ls,l,mid
#define RS rs,mid+1,r
using namespace std;
const int N=55;
const int M=2055;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
inline int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
void gmin(int &x,int y){x=min(x,y);}
int n,s,m;
int ans=inf;
char col[N];
int dp[N][M];
int r[N];
signed main()
{
	memset(dp,0x3f,sizeof(dp));
	rd(n);rd(s);rd(m);
	for (int i=1;i<=n;i++) rd(r[i]);
	for (int i=1;i<=n;i++) cin>>col[i];
	for (int i=1;i<=n;i++) dp[i][r[i]]=abs(i-s);
	for (int j=1;j<=m+50;j++) for (int i=1;i<=n;i++) for (int k=1;k<=n;k++)
	if (col[i]!=col[k] && r[i]<r[k]) gmin(dp[k][j+r[k]],dp[i][j]+abs(i-k));
	for (int i=1;i<=n;i++) for (int j=m;j<=m+50;j++) gmin(ans,dp[i][j]);
	if (ans==inf) puts("-1");else cout<<ans<<endl;
}