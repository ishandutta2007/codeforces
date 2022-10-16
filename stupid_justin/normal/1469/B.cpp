#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=5005;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
 
int n,k,sum,Max1,Max2;
string s;
int a[N];
int dp[N][2];
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		Max1=Max2=0;
		cin>>n;for (int i=1;i<=n;i++) cin>>k,sum+=k,Max1=max(Max1,sum);sum=0;
		cin>>n;for (int i=1;i<=n;i++) cin>>k,sum+=k,Max2=max(Max2,sum);sum=0;
		cout<<Max1+Max2<<endl;
			
	}
}