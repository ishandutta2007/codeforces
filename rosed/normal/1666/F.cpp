#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 zmakioi
const int N=5010,mod=998244353;
int n,opt,ans;
int a[N];
int f[2][N];
int C[N][N];
int fac[N],inv[N];
inline int fast(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}
inline void work(int x,int t)
{
	for(int i=0;i<=n+1;++i) f[t][i]=0;
	for(int i=0;i<=n;++i)
	{
		if(i+(x-1)>=0&&i+(x-1)<=n&&i+1<=n) f[t][i+1]=(f[t][i+1]+f[t^1][i+(x-1)]*C[i+x-1][x-1]%mod)%mod;
	}
	for(int i=0;i<=n;++i)
	{
		if(i+x<=n) f[t][i]=(f[t][i]+f[t^1][i+x]*C[i+x][x]%mod)%mod;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	for(int i=0;i<=5000;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	fac[0]=inv[0]=1;
	for(int i=1;i<=5000;++i) fac[i]=fac[i-1]*i%mod;
	inv[5000]=fast(fac[5000],mod-2);
	for(int i=4999;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
	while(T--)
	{
		cin>>n;opt=0;ans=0;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		if(a[n]==a[n-1])
		{
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<=n+1;++i) f[0][i]=f[1][i]=0;
		f[0][0]=1;
		for(int i=n-1;i>=1;--i)
		{
			//a[i]
			int sum=fac[i-1]*f[opt][i-1]%mod;
			int r=i-1,l=i-1;
			while(r>1)
			{
				while(a[l-1]==a[r]) --l;
				sum=sum*inv[r-l+1]%mod;
				r=l-1;
			}
			ans=(ans+sum)%mod;
			//cout<<sum<<"!!"<<endl;
			opt^=1;
			r=i,l=i;
			while(a[l-1]==a[r]) --l;
			work(r-l+1,opt);
			i=l;
			 // cout<<i<<'\n';
			 // for(int j=0;j<=n;++j) cout<<f[opt][j]<<" \n"[j==n];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1
5
1 1 2 2 3

*/