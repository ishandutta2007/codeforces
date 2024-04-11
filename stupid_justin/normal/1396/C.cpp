#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}

int n;
int r1,r2,r3,d;
int a[N];
int dp[N][2];
signed main()
{
	rd(n);
	rd(r1);rd(r2);rd(r3);rd(d);
	for (int i=1;i<=n;i++) rd(a[i]);
	dp[1][0]=r1*a[1]+r3;
	dp[1][1]=min(r2,r1*(a[1]+1));
	for (int i=1;i<n;i++)
	{
		int k=a[i+1]+1;
		int t=min(r2,r1*k);
		int m=r1*(k-1);
		dp[i+1][1]=dp[i][0]+t+d;
		dp[i+1][1]=min(dp[i+1][1],dp[i][1]+d+t+r1+2*d);
		dp[i+1][0]=dp[i][0]+m+r3+d;
		dp[i+1][0]=min(dp[i+1][0],dp[i][1]+d+m+r3+d+r1+d);
		dp[i+1][0]=min(dp[i+1][0],dp[i][1]+d+t+2*d+2*r1);
	}
	cout<<min(dp[n][0],dp[n-1][1]+d+r1*a[n]+r3+d+r1)<<endl;
}