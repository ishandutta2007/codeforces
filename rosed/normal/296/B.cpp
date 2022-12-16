#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=5e5+10,mod=1e9+7;
	char a[N],b[N];
	int dp[N][4];
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int n;cin>>n;
		cin>>(a+1)>>(b+1); 
		dp[0][0]=1;
		for(int i=1;i<=n;++i)
		{
			if(a[i]=='?')
			{
				if(b[i]=='?')
				{
					dp[i][0]=dp[i-1][0]*10;
					dp[i][1]=(dp[i-1][0]*45+dp[i-1][1]*55)%mod;
					dp[i][2]=(dp[i-1][0]*45+dp[i-1][2]*55)%mod;
					dp[i][3]=((dp[i-1][1]+dp[i-1][2])*45+dp[i-1][3]*100)%mod;
				}
				else
				{
					dp[i][0]=dp[i-1][0];
					dp[i][1]=(dp[i-1][0]*(b[i]-'0')+dp[i-1][1]*(b[i]-'0'+1))%mod;
					dp[i][2]=(dp[i-1][0]*('9'-b[i])+dp[i-1][2]*('9'-b[i]+1))%mod;
					dp[i][3]=(dp[i-1][1]*('9'-b[i])+dp[i-1][2]*(b[i]-'0')+dp[i-1][3]*10)%mod;
				}
			}
			else
			{
				if(b[i]=='?')
				{
					dp[i][0]=dp[i-1][0];
					dp[i][1]=(dp[i-1][0]*('9'-a[i])+dp[i-1][1]*('9'-a[i]+1))%mod;
					dp[i][2]=(dp[i-1][0]*(a[i]-'0')+dp[i-1][2]*(a[i]-'0'+1))%mod;
					dp[i][3]=(dp[i-1][1]*(a[i]-'0')+dp[i-1][2]*('9'-a[i])+dp[i-1][3]*10)%mod;
				}
				else
				{
					if(a[i]==b[i])
					{
						dp[i][0]=dp[i-1][0];
						dp[i][1]=dp[i-1][1];
						dp[i][2]=dp[i-1][2];
						dp[i][3]=dp[i-1][3];
					}
					else if(a[i]<b[i])
					{
						dp[i][1]=(dp[i-1][0]+dp[i-1][1])%mod;
						dp[i][3]=(dp[i-1][2]+dp[i-1][3])%mod;
					}
					else
					{
						dp[i][2]=(dp[i-1][0]+dp[i-1][2])%mod;
						dp[i][3]=(dp[i-1][1]+dp[i-1][3])%mod;
					}
				}
			}
		}
		cout<<dp[n][3]<<'\n';
	}
}
signed main()
{
	red::main();
	return 0;
}
/*

kkkljkk
*/