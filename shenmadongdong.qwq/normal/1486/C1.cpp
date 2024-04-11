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
#define Z(a) sort(a+1,a+n+1)
using namespace std;
const unsigned _mod=998244353;
const unsigned mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(auto &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y){ll ret=1;while(y){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,x;
int ask(int x,int y){if (!(x^y)) return 0;cout<<"? "<<x<<" "<<y<<endl;rd(x);return x;}
void work(int l,int r,int p)
{
	if (l==r) cout<<"! "<<l<<endl;
	if (l==r-1) cout<<"! "<<l+r-p<<endl;
	if (l==r||l==r-1) exit(0);
	int mid=l+r>>1;
	if (p<=mid)
	{
		x=ask(l,mid);
		if (x==p) work(l,mid,p);
		else 
		{
			x=ask(mid+1,r);
			work(mid+1,r,x);
		}
	} 
	else 
	{
		x=ask(mid+1,r);
		if (x==p) work(mid+1,r,p); 
		else 
		{
			x=ask(l,mid);
			work(l,mid,x);
		}
	}
}
int main()
{
	cin>>n;
	cout<<"? "<<1<<' '<<n<<endl;
	rd(x);
	work(1,n,x);
	return 0;
}