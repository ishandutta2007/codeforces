// new day,new strength,new thougts

#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1010;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

vector<ll>is,isnt;
bool gov[maxn],vis[maxn];
bool seen;
ll SZ;

vector<ll>v[maxn];

void dfs(ll u){
	vis[u]=1;
	SZ++;
	seen|=gov[u];
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(!vis[y])
			dfs(y);
	}
}

inline ll C2(ll x){
	return (x*(x-1))/2;
}

int main(){
	ll n,m,k;cin>>n>>m>>k;
	REP(i,k){
		ll x;cin>>x;
		gov[x]=1;
	}
	REP(i,m){
		ll a,b;cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
	}
	FOR(i,1,n){
		if(!vis[i]){
			seen=0;
			SZ=0;
			dfs(i);
			if(seen)
				is.PB(SZ);
			else
				isnt.PB(SZ);
		}
	}
	ll ans=0,mx=0;
	REP(i,sz(is)){
		ans+=C2(is[i]);
		mx=max(mx,is[i]);
	}
	REP(i,sz(isnt)){
		ans+=C2(isnt[i]);
		ans+=isnt[i]*mx;
		mx+=isnt[i];
	}
	ans-=m;
	cout<<ans;
}