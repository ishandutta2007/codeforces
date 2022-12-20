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

const ll inf=4e18;
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

vector<ll>v[maxn];
ll h[maxn];
ll a[maxn];
bool is[maxn];
ll cnt[maxn];
ll ans;
ll n,k;

void dfs_cnt(ll u,ll par=-1){
	cnt[u]=is[u];
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=par){
			dfs_cnt(y,u);
			cnt[u]+=cnt[y];
		}
	}
}

void dfs_h(ll u,ll par=-1){
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=par){
			h[y]=h[u]+1;
			dfs_h(y,u);
		}
	}
}

ll find_center(ll u,ll par=-1){
	ll mx=0,mxind=-1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=par){
			if(mx<cnt[y]){
				mx=cnt[y];
				mxind=y;
			}
		}
	}
	if(mx<=k)
		return u;
	return find_center(mxind,u);
}

int main(){
	cin>>n>>k;
	REP(i,2*k){
		cin>>a[i];
		is[a[i]]=1;
	}
		
	REP(i,n-1){
		ll a,b;cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
	}
	dfs_cnt(1);
	ll center=find_center(1);
	dfs_h(center);
	REP(i,2*k)
		ans+=h[a[i]];
	cout<<ans;
}