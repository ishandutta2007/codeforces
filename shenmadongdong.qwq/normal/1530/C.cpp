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
const unsigned _mod=998244353;
const unsigned mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(int &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y>0){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,a[100010],b[100010],prea[100010],preb[100010];
inline int f(int x){return x-x/4;}
int main()
{
	DC
	{
		int cnt=0;
		cin>>n;
    	F(i) rd(a[i]);
    	F(i) rd(b[i]);
	    Z(a,n),Z(b,n);
	    reverse(a+1,a+n+1);
	    reverse(b+1,b+n+1);
	    F(i) preb[i]=preb[i-1]+b[i];
    	F(i) prea[i]=prea[i-1]+a[i];
    	int g=prea[f(n)],h=preb[f(n)];
    	while(h>g)
    	{
   	     	g=100*(cnt+1)+prea[f(n+cnt+1)-cnt-1];
   	     	h=preb[min(f(n+cnt+1),n)];
   	     	cnt++;
    	}
    	cout<<cnt<<'\n';
	}
	return 0;
}