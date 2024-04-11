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
int n,k,x[110],y[110],t[210];
bool b[210];
bool chk(int p,int q)
{
	return ((x[p]<x[q]&&x[q]<y[p])&&!(x[p]<y[q]&&y[q]<y[p]));
}
int main()
{
	DC
	{
		M(b,0);
		cin>>n>>k; 
		rep(i,1,k) rd(x[i]),rd(y[i]);
		rep(i,1,k) b[x[i]]=b[y[i]]=1;
		int cnt=0;
		rep(i,1,2*n) if (!b[i]) t[++cnt]=i;
		rep(i,1,n-k) x[i+k]=t[i],y[i+k]=t[i+cnt/2];
		F(i) if (x[i]>y[i]) swap(x[i],y[i]);
		int ans=0;
		F(i) F(j) if (i!=j) ans+=chk(i,j);
		cout<<ans<<'\n';
	}
	return 0;
}