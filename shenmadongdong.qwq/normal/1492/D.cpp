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
void rd(auto &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y){ll ret=1;while(y){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int a,b,k;
bool s[200010],t[200010];
int main()
{
    cin>>a>>b>>k;
	if (!k)
	{
		puts("Yes");
		rep(i,1,b) putchar(49);
		rep(i,1,a) putchar(48);
		putchar(10);
		rep(i,1,b) putchar(49);
		rep(i,1,a) putchar(48);
		putchar(10);
		return 0;
	}
	if (!a||b==1||k>=a+b-1) return puts("No"),0;
	s[1]=t[1]=1;
	t[a+b]=1;
	s[a+b-k]=1;
	int p=b-2;
	rep(i,1,a+b) 
	{
		if (!p) break;
		if (!s[i]&&!t[i]) s[i]=t[i]=1,p--;
		if (!p) break;
	}
	puts("Yes");
	rep(i,1,a+b) putchar(48+s[i]);
	putchar(10);
	rep(i,1,a+b) putchar(48+t[i]);
	putchar(10);
	return 0;
}