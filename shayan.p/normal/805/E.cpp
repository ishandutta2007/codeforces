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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=3e5+10;
const ll maxnum=5e5+10;

vector<ll>v[maxn];
vector<ll>ice[maxn];
ll color[maxn];
bool mark[maxnum];

void dfs(ll u,ll par=-1){
	vector<ll>nseen;
	stack<ll>used;
	REP(i,sz(ice[u])){
		if(color[ice[u][i]]==0){
			nseen.PB(ice[u][i]);
		}
		else{
			mark[color[ice[u][i]]]=1;
			used.push(color[ice[u][i]]);
		}
	}
	
	ll ind=1;
	REP(i,sz(nseen)){
		while(mark[ind]){
			ind++;
		}
		color[nseen[i]]=ind;
		ind++;
	}
	while(sz(used)){
		mark[used.top()]=0;
		used.pop();
	}
	
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=par)
			dfs(y,u);
	}
}
int main(){
	ll n,m,mx=1;cin>>n>>m;
	FOR(i,1,n){
		ll t;cin>>t;
		mx=max(mx,t);
		REP(j,t){
			ll x;cin>>x;
			ice[i].PB(x);
		}
	}
	REP(i,n-1){
		ll a,b;cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
	}
	dfs(1);
	cout<<mx<<endl;
	FOR(i,1,m){
		if(color[i]==0)color[i]=1;//not seen in any sets
		cout<<color[i]<<" ";
	}
}