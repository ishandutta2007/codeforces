#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 10007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

#define SZ 233333
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
namespace linear_seq {
inline vector<int> BM(vector<int> x)
{
	//ls: (shortest) relation sequence (after filling zeroes) so far
	//cur: current relation sequence
	vector<int> ls,cur;
	//lf: the position of ls (t')
	//ld: delta of ls (v')
	int lf,ld;
	for(int i=0;i<int(x.size());++i)
	{
		ll t=0;
		//evaluate at position i
		for(int j=0;j<int(cur.size());++j)
			t=(t+x[i-j-1]*(ll)cur[j])%MOD;
		if((t-x[i])%MOD==0) continue; //good so far
		//first non-zero position
		if(!cur.size())
		{
			cur.resize(i+1);
			lf=i; ld=(t-x[i])%MOD;
			continue;
		}
		//cur=cur-c/ld*(x[i]-t)
		ll k=-(x[i]-t)*qp(ld,MOD-2)%MOD/*1/ld*/;
		vector<int> c(i-lf-1); //add zeroes in front
		c.pb(k);
		for(int j=0;j<int(ls.size());++j)
			c.pb(-ls[j]*k%MOD);
		if(c.size()<cur.size()) c.resize(cur.size());
		for(int j=0;j<int(cur.size());++j)
			c[j]=(c[j]+cur[j])%MOD;
		//if cur is better than ls, change ls to cur
		if(i-lf+(int)ls.size()>=(int)cur.size())
			ls=cur,lf=i,ld=(t-x[i])%MOD;
		cur=c;
	}
	for(int i=0;i<int(cur.size());++i)
		cur[i]=(cur[i]%MOD+MOD)%MOD;
	return cur;
}
int m; //length of recurrence
//a: first terms
//h: relation
ll a[SZ],h[SZ],t_[SZ],s[SZ],t[SZ];
//calculate p*q mod f
inline void mull(ll*p,ll*q)
{
	for(int i=0;i<m+m;++i) t_[i]=0;
	for(int i=0;i<m;++i) if(p[i])
		for(int j=0;j<m;++j)
			t_[i+j]=(t_[i+j]+p[i]*q[j])%MOD;
	for(int i=m+m-1;i>=m;--i) if(t_[i])
		//miuns t_[i]x^{i-m}(x^m-\sum_{j=0}^{m-1} x^{m-j-1}h_j)
		for(int j=m-1;~j;--j)
			t_[i-j-1]=(t_[i-j-1]+t_[i]*h[j])%MOD;
	for(int i=0;i<m;++i) p[i]=t_[i];
}
inline ll calc(ll K)
{
	for(int i=m;~i;--i)
		s[i]=t[i]=0;
	//init
	s[0]=1; if(m!=1) t[1]=1; else t[0]=h[0];
	//binary-exponentiation
	while(K)
	{
		if(K&1) mull(s,t);
		mull(t,t); K>>=1;
	}
	ll su=0;
	for(int i=0;i<m;++i) su=(su+s[i]*a[i])%MOD;
	return (su%MOD+MOD)%MOD;
}
inline int work(vector<int> x,ll n)
{
	if(n<int(x.size())) return x[n];
	vector<int> v=BM(x); m=v.size(); if(!m) return 0;
	
	for(int i=0;i<m;++i) h[i]=v[i],a[i]=x[i];
	return calc(n);
}
}
using linear_seq::work;

int n,dp[1005][201][201],sta;
bool st;
string s;
vector<int> sq;

int f(int rem,int le,int ri){
	if(!rem)return le>ri;
	if(ri<0)ri = 0;
	int &ret = dp[rem][le][ri];
	if(ret!=-1)return ret;
	
	if(le>ri)return ret = 26*f(rem-1,le,ri)%MOD;
	if(rem==1 && st && le!=ri)return ret = 0;
	
	if(s[le]==s[ri])ret = (25*f(rem-1,le,ri) + f(rem-1,le+1,ri-1))%MOD;
	else ret = ret = (24*f(rem-1,le,ri) + f(rem-1,le,ri-1) + f(rem-1,le+1,ri))%MOD;
	return ret;
}

int main(){
// cout<<fixed<<setprecision(3);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>n;
    if((n+s.size())&1)st = 1;
    mems(dp,-1);
    sta = s.size();
    if(n&1)++sta;
    sta = (sta+1)/2;
    
    rep(i,0,900)sq.pb(f(sta+i,0,s.size()-1));
    
    cout<<work(sq,n/2)<<endl;
    return 0;
}