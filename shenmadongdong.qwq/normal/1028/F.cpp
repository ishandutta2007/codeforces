#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const int mod=998244353;
const int _mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
template <typename T> void rd(T &x){x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y){if(y&1)ret=ret*x;y>>=1;x=x*x;}return ret;}
/*
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
int n,s,op,x,y;
__gnu_pbds::gp_hash_table<double,int> mp;
__gnu_pbds::gp_hash_table<ll,set<pair<int,int> > > mp2;
void ins(set<pair<int,int> > a,int x,int y,int z) {
	s+=z,mp[1.0*y/x]+=z;
	for(pair<int,int> u:a) mp[(u.second+y)*1.0/(u.first+x)]+=2*z;
}
int main()
{
	DC
	{
		rd(op),rd(x),rd(y);
		ll dis=qpow(x)+qpow(y);
		if (op==1) ins(mp2[dis],x,y,1),mp2[dis].insert({x,y});
		if (op==2) mp2[dis].erase({x,y}),ins(mp2[dis],x,y,-1);
		if (op==3) cout<<s-mp[y*1.0/x]<<'\n';
	}
	return 0;
}