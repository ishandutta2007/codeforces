#include<bits/stdc++.h>
#define int long long 
#define rd(x) x=read()
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
inline int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
inline int INV(int x){return ksm(x,mod-2);}
int fac[maxn],inv[maxn];
 
void init()
{
    fac[0]=1;for (int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=INV(fac[maxn-1]);for (int i=maxn-2;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int n,int m)
{
	if (m==n || m==0) return 1;
	if (m>n || m<0) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
	
}
int n,cnt;
vector<pair<int,int> > ans;
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		ans.clear();
		cin>>n;
		while (n>2)
		{
			int s=sqrt(n-1)+1;
			for (int i=s+1;i<=n-1;i++) ans.push_back(make_pair(i,n));
			ans.push_back(make_pair(n,s));
			ans.push_back(make_pair(n,s));
			n=s;
		}
		cout<<ans.size()<<endl;
		for (int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}