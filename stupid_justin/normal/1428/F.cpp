#include<bits/stdc++.h>
#define int long long 
#define rd(x) x=read()
using namespace std;
const int N=1e6+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;

inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
inline int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
int n,cnt,ans,sum;
int f[N];
string s;
signed main()
{
	
	cin>>n>>s;s=" "+s;
	for (int i=1;i<=n;i++) f[i]=n+1;
	for (int i=n;i>=1;i--)
	{
		if (s[i]=='1') cnt++,sum+=f[cnt]-i;
		else while (cnt) f[cnt]=i+cnt,cnt--;
		ans+=sum; 
	}
	cout<<ans<<endl;
}