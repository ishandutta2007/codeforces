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
const ll infi=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(auto &x){x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y){if(y&1)ret=ret*x;y>>=1;x=x*x;}return ret;}
/*
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,k,s[10010],p[10010];
int main()
{
	cin>>n>>k;
	rep(i,2,n) 
	{
		int x;
		cout<<"or 1 "<<i<<endl;
		rd(x);s[i]=x;
		cout<<"and 1 "<<i<<endl;
		rd(x);s[i]+=x;
	}
	int pq,x;
	cout<<"or 2 3"<<endl;
	rd(x);pq=x;
	cout<<"and 2 3"<<endl;
	rd(x);pq+=x;
	rep(i, 2, n) p[i] = s[i] - (s[2] + s[3] - pq) / 2;
	p[1]=(s[2] + s[3] - pq) / 2;
	stable_sort(p+1,p+n+1);
	cout<<"finish "<<p[k]<<endl;
	return 0;
}