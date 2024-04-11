#include<bits/stdc++.h>
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
#define rd(x) x=read()
using namespace std;
const unsigned mod=998244353;
const unsigned _mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y){ll ret=1;while(y){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int h,m,hh,mm,c[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
string s;
bool chk(int x,int y)
{
	if (c[x/10]==-1||c[x%10]==-1) return 0;
	if (c[y/10]==-1||c[y%10]==-1) return 0;
	if (c[y/10]+c[y%10]*10>=h||c[x%10]*10+c[x/10]>=m) return 0;
	return 1;
}
int main()
{
	DC
	{
		cin>>h>>m>>s;
		hh=(s[0]-48)*10+s[1]-48;
		mm=(s[3]-48)*10+s[4]-48;
		while(!chk(hh,mm))
		{
			mm++;
			if (mm==m) mm=0,hh++;
			if (hh==h) hh=0;
		}
		if (hh<10) putchar(48);
		cout<<hh<<':';
		if (mm<10) putchar(48);
		cout<<mm<<'\n';
	}
	return 0;
}