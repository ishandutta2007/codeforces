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
int a,b,n,m;
vector<int> wzak;
int main()
{
	DC
	{
		wzak.clear();
		cin>>a>>b;
		m=a+b>>1;
		n=a+b-m;
		rep(i,0,n)
		{
			int A=i,C=b-n+i,D=m-b+n-i;
			if (C>=0&&D>=0&&A+D==a) wzak.emplace_back(A+C);
		}
		rep(i,0,m)
		{
			int A=i,C=b-m+i,D=n-b+m-i;
			if (C>=0&&D>=0&&A+D==a) wzak.emplace_back(A+C);
		}
		sort(wzak.begin(),wzak.end());
		int p=unique(wzak.begin(),wzak.end())-wzak.begin();
		cout<<p<<'\n';
		rep(i,0,p-1) cout<<wzak[i]<<' ';
		putchar(10);
	}
	return 0;
}