#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
#define seg(x,y) (seg){x,y}
using namespace std;
const int N=105;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
 
int n;
struct seg{int p,len;}S[N];
bool cmp(seg x,seg y){return x.p!=y.p?x.p<y.p:x.len<y.len;}
int ans;
int dp[N][N][2];
signed main()
{
	rd(n);
	for (int i=1;i<=n;i++){rd(S[i].p);rd(S[i].len);}
	sort(S+1,S+n+1,cmp);
	S[0].p=-1e9;
	for (int i=0;i<=n;i++) for (int j=0;j<=i;j++)
	for (int p=0;p<=1;p++)
	{
		ans=max(ans,dp[i][j][p]);
		int o=S[j].p+p*S[j].len;
		int Max=-1e9,x,y;
		for (int k=i+1;k<=n;k++) for (int q=0;q<=1;q++)
		{
			int t=S[k].p+q*S[k].len;
			if (t>Max) Max=t,x=k,y=q;
			dp[k][x][y]=max(dp[k][x][y],dp[i][j][p]+min(S[k].len,t-o)+Max-t);
		}
	}
	cout<<ans<<endl;
}