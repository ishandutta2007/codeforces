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
const ll mod=1e9+7;
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

ll SZ;
set<ll>s;
vector<ll>v[maxn];
ll n,m;

void dfs(ll u){
	if(!sz(v[u])){
		cout<<1<<endl<<n;
		exit(0);
	}
	s.erase(u);
	SZ++;
	ll bef=inf;
	REP(i,sz(v[u])){
		set<ll>::iterator it=s.upper_bound(v[u][i]);
		while(it!=s.end()&&(*it)<bef){
			dfs(*it);
			it=s.upper_bound(v[u][i]);
		}
		bef=v[u][i];
	}
	while(sz(s)&&(*s.begin())<v[u].back())
		dfs(*s.begin());
}

int main(){
	cin>>n>>m;
	REP(i,m){
		ll a,b;cin>>a>>b;
		a--;b--;
		v[a].PB(b);
		v[b].PB(a);
	}
	REP(i,n)
		sort(v[i].begin(),v[i].end(),greater<ll>());
	REP(i,n)
		s.insert(i);
	vector<ll>ans;
	while(sz(s)){
		SZ=0;
		dfs(*s.begin());
		ans.PB(SZ);
	}
	sort(ans.begin(),ans.end());
	cout<<sz(ans)<<endl;
	REP(i,sz(ans))
		cout<<ans[i]<<" ";
}