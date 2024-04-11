#include<bits/stdc++.h>
#define ri int
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define endl '\n'
using namespace std;

const int N=2e5+5;
const int mod=1e9+7;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,p;
int a[N];
__int128 dp[N],k;
signed main()
{
	int T;cin>>T;
	while (T--)
	{
		rd(n);rd(k);
		memset(dp,0,sizeof(dp));
		dp[n+1]=1;
		bool flag=0;
		for (int i=n;i>=1;i--)
		{
			for (int j=i+1;j<=n+1;j++) dp[i]+=dp[j];
			if (dp[i]>=k) {p=i-1;flag=1;break;}
		}
		if (!flag) {puts("-1");continue;}
		for (int i=1;i<=p;i++) a[i]=i;
		while (p<n)
		{
			for (int i=p+2;i<=n+1;i++)
			{
				k-=dp[i];
				if (k<=0)
				{
					k+=dp[i];
					a[p+1]=i-1;
					for (int j=p+2;j<=i-1;j++) a[j]=a[j-1]-1;
					p=i-1;break;
				}
			}
		}
		for (int i=1;i<=n;i++) cout<<a[i]<<" ";puts("");
	}
}