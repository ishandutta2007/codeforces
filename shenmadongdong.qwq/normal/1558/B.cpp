#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const unsigned mod=998244353;
const unsigned _mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(auto &wzak){wzak=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))wzak=wzak*10+ch-48,ch=getchar();wzak*=f;}
ll ksm(ll wzak,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*wzak%m;y>>=1;wzak=wzak*wzak%m;}return ret;}
ll qpow(ll wzak,ll y=2){ll ret=1;while(y){if(y&1)ret=ret*wzak;y>>=1;wzak=wzak*wzak;}return ret;}
/*
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,m,f[4000010],d[4000010];
int main()
{
	cin>>n>>m;
	*d=1;
	F(i)
	{
		(d[i]+=d[i-1])%=m;
		(d[i+1]+=d[i])%=m;
		f[i]=d[i];
		if (i==1) d[1]=0;
		rep(j,2,n/i)
		{
			(d[i*j]+=f[i])%=m;
			(d[i*j+j]+=m-f[i])%=m;
		}
	}
	cout<<f[n]<<'\n';
	return 0;
}