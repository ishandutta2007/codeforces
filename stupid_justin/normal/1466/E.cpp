#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=5e5+5;
const int M=5005;
const int mod=1e9+7;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
 
int n,ans;
int s[62];
int a[N];
signed main()
{
	int Q;
	cin>>Q;
	while (Q--)
	{
		rd(n);
		ans=0;
		for (int i=1;i<=60;i++) s[i]=0;
		for (int i=1;i<=n;i++)
		{
			rd(a[i]);int x=a[i];
			for (int j=1;j<=60;j++) 
			{
				s[j]+=x&1;
				x>>=1;
			}
		}
		for (int i=1;i<=n;i++)
		{
			int tmp1=0,tmp2=0;
			for (int j=1;j<=60;j++)
			{
				int k=(1ll<<(j-1))%mod;
				k*=s[j];
				if (a[i]>>(j-1)&1)tmp1=(tmp1+k)%mod;
			}
			for (int j=1;j<=60;j++)
			{
				int k=(1ll<<(j-1))%mod;
				if (a[i]>>(j-1)&1) k*=n; else k*=s[j];
				tmp2=(tmp2+k)%mod;
			}
			ans=(ans+tmp1*tmp2)%mod;
		}
		cout<<ans<<'\n';
	}
	
}