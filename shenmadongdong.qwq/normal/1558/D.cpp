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
void rd(auto &x){x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y){if(y&1)ret=ret*x;y>>=1;x=x*x;}return ret;}
/*
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
const int JS=4e5;
ll fac[JS+10],inv[JS+10];
ll C(ll n,ll m){if(m>n||m<0)return 0;return fac[n]*inv[m]%mod*inv[n-m]%mod;}
mt19937 rnd(time(0));
int n,m,cnt,rt,a,b,x,y;
struct wzak{
  	int val,sz,tag,rd,ls,rs;
}t[500010];
int made(int val)
{
  	int id=++cnt;
  	t[id].val=val;
  	t[id].sz=1;
  	t[id].ls=t[id].rs=t[id].tag=0;
  	t[id].rd=rnd();
  	return id;
}
void pushdown(int x)
{
  	if (!t[x].tag) return;
    if (t[x].ls) t[t[x].ls].tag+=t[x].tag,t[t[x].ls].val+=t[x].tag;
    if (t[x].rs) t[t[x].rs].tag+=t[x].tag,t[t[x].rs].val+=t[x].tag;
	t[x].tag=0;
}
void split(int p,int k,int &x,int &y)
{
  	if (!p) return x=y=0,void();
  	pushdown(p);
  	if (k<t[p].val) y=p,split(t[p].ls,k,x,t[p].ls);
	else x=p,split(t[p].rs,k,t[p].rs,y);
  	t[p].sz=t[t[p].ls].sz+t[t[p].rs].sz+1;
}
int merge(int x,int y)
{
	if (!x) return y;
  	if (!y) return x;
  	if (t[x].rd>=t[y].rd)
  	{
  	  	pushdown(y);
  	  	t[y].ls=merge(x,t[y].ls);
  	  	t[y].sz=t[t[y].ls].sz+t[t[y].rs].sz+1;
  	  	return y;
  	}
  	pushdown(x);
  	t[x].rs=merge(t[x].rs,y);
  	t[x].sz=t[t[x].ls].sz+t[t[x].rs].sz+1;
  	return x;
}
bool find(int x,int p)
{
  	if (!p) return 0;
  	if (t[p].val==x) return 1;
  	pushdown(p);
  	if (x>=t[p].val) return find(x,t[p].rs);
  	return find(x,t[p].ls);
}
int main()
{
	*fac=*inv=1;
	rep(i,1,JS) fac[i]=fac[i-1]*i%mod;
	rep(i,1,JS) inv[i]=ksm(fac[i]);
	DC
	{
  		rt=cnt=0;
		cin>>n>>m;
  		rep(i,1,m)
  		{
  		  	rd(a),rd(b);
  		  	bool f=find(b,rt);
  		  	split(rt,b-1,x,y);
  		  	if (y) t[y].tag++,t[y].val++;
  		  	if (f) rt=merge(x,y);
  		  	else rt=merge(x,merge(made(b+1),y));
  		}
  		cout<<C(2*n-cnt-1,n)<<'\n';
	}
  	return 0;
}