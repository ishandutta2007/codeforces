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
ll read(){ll x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y){ll ret=1;while(y){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,u,r,l,d,tl,t,sl,s;
int main()
{
	DC
	{
		bool flag=0;
		cin>>n>>u>>r>>d>>l;
		t=tl=s=sl=0;
		if (u==n) tl++,t+=2;
		if (d==n) tl++,t+=2;
		if (u==n-1) t++;
		if (d==n-1) t++;
		if (l==n) sl++,s+=2;
		if (r==n) sl++,s+=2;
		if (l==n-1) s++;
		if (r==n-1) s++;
		if (u<sl||d<sl||l<tl||r<tl) flag=1;
		if (u+d<s||l+r<t) flag=1;
		u=n-u,r=n-r,l=n-l,d=n-d;
		t=tl=s=sl=0;
		if (u==n) tl++,t+=2;
		if (d==n) tl++,t+=2;
		if (u==n-1) t++;
		if (d==n-1) t++;
		if (l==n) sl++,s+=2;
		if (r==n) sl++,s+=2;
		if (l==n-1) s++;
		if (r==n-1) s++;
		if (u<sl||d<sl||l<tl||r<tl) flag=1;
		if (u+d<s||l+r<t) flag=1;
		puts(flag?"NO":"YES");
	}
	return 0;
}