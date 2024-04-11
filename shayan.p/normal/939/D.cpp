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
const ll mod=1e9+7;
const ll maxc=30;

#pragma GCC Optimize("Ofast")

vector<ll> v[maxc];
vector<pll>ans;
bool mark[maxc];

void dfs(ll u){
	mark[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(!mark[y]){
			ans.PB(MP(u,y));
			dfs(y);
		}
	}
}

int main(){
	ll n;cin>>n;
	string s1,s2;cin>>s1>>s2;
	REP(i,n){
		v[s1[i]-'a'].PB(s2[i]-'a');
		v[s2[i]-'a'].PB(s1[i]-'a');
	}
	REP(i,maxc){
		if(!mark[i])
			dfs(i);
	}
	cout<<sz(ans)<<endl;
	REP(i,sz(ans))
		cout<<char(ans[i].F+'a')<<" "<<char(ans[i].S+'a')<<endl;
}