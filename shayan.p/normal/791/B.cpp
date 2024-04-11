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
const ll mod=1e9+7;
const ll maxn=2e5+10;

vector<ll>v[maxn];
ll mark[maxn];
vector<ll>con;

void dfs(ll u){
	con.PB(u);
	mark[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(!mark[y]){
			dfs(y);
		}
	}
}
int main(){
	ll n,m;cin>>n>>m;
	REP(i,m){
		ll a,b;cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
	}
	FOR(i,1,n){
		if(!mark[i]){
			con.clear();
			dfs(i);
			REP(j,sz(con)){
				if(sz(v[con[j]])!=sz(con)-1){
					cout<<"NO";
					return 0;
				}
			}
		}
	}
	cout<<"YES";
}