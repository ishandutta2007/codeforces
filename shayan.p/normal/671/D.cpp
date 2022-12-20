// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e15;
const ll maxn=3e5+10;

ll dp[maxn];
vector<ll>st[maxn];
vector<ll>en[maxn];
vector<ll>v[maxn];
ll t;// last not used
ll number[maxn];
pll seg[maxn];

ll val[4*maxn],lazy[4*maxn];
ll ee[maxn],ss[maxn],cc[maxn];

void get(ll l,ll r,ll ind){
	if(lazy[ind]>=inf)
		lazy[ind]=inf;
	val[ind]+=lazy[ind];
	if(val[ind]>=inf)
		val[ind]=inf;
	if(l!=r){
		lazy[2*ind]+=lazy[ind];
		lazy[2*ind+1]+=lazy[ind];
	}
	lazy[ind]=0;
}

void add(ll f,ll s,ll x,ll l=0,ll r=maxn-1,ll ind=1){
	if(l>r)return;
	if(s<l||r<f)return;
	if(f<=l&&r<=s){
		lazy[ind]+=x;
		get(l,r,ind);
		return;
	}
	ll mid=(l+r)/2;
	add(f,s,x,l,mid,2*ind);
	add(f,s,x,mid+1,r,2*ind+1);
	val[ind]=min(val[2*ind],val[2*ind+1]);
}

ll Min(ll f,ll s,ll l=0,ll r=maxn-1,ll ind=1){
	if(l>r)return inf;
	get(l,r,ind);
	if(s<l||r<f)return inf;
	if(f<=l&&r<=s){
		return val[ind];
	}
	ll mid=(l+r)/2;
	return min(Min(f,s,l,mid,2*ind),Min(f,s,mid+1,r,2*ind+1));
}

void asgn(ll targ,ll x,ll l=0,ll r=maxn-1,ll ind=1){
	if(l>r)return;
	get(l,r,ind);
	if(targ<l||r<targ)return;
	if(l==targ&&r==targ){
		val[ind]=x;
		return;
	}
	ll mid=(l+r)/2;
	asgn(targ,x,l,mid,2*ind);
	asgn(targ,x,mid+1,r,2*ind+1);
	val[ind]=min(val[2*ind],val[2*ind+1]);
}

void dfs(ll u,ll par=-1){
	ll bef=t;
	REP(i,sz(v[u]))
		if(v[u][i]!=par)
			dfs(v[u][i],u);
	REP(i,sz(en[u]))
		number[en[u][i]]=t++;
	seg[u]=MP(bef,t-1);
}

ll Sub(ll u,ll par=-1){
	ll sm=0;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=par){
			Sub(y,u);
			dp[y]=Min(seg[y].F,seg[y].S);// if seg[y].F>seg[y].S returnrs inf
			if(dp[y]==inf){
				cout<<-1;
				exit(0);
			}
			sm+=dp[y];
		}
	}
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=par){
			add(seg[y].F,seg[y].S,sm-dp[y]);
		}
	}
	REP(i,sz(en[u]))
		asgn(number[en[u][i]],sm+cc[en[u][i]]);
	REP(i,sz(st[u]))
		asgn(number[st[u][i]],inf);
	return sm;
}

int main(){
	ll n,m;cin>>n>>m;
	fill(val,val+4*maxn,inf);
	REP(i,n-1){
		ll a,b;cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
	}
	REP(i,m){
		cin>>ee[i]>>ss[i]>>cc[i];
		en[ee[i]].PB(i);
		st[ss[i]].PB(i);
	}
	dfs(1);
	cout<<Sub(1);
}