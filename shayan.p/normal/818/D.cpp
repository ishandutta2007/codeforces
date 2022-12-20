// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
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
const ll maxn=1e6+1;

vector<ll>v[maxn];
int main(){
	ll n,a,h=0;cin>>n>>a;
	REP(i,n){
		ll x;cin>>x;
		if(x==a){
			h++;
			continue;
		}
		v[x].PB(h);
	}
	FOR(i,1,maxn-1){//colors
		if(i==a)continue;
		if(sz(v[i])<h)continue;
		bool yes=1;
		REP(j,sz(v[i])){
			if(j<v[i][j]){
				yes=0;
				break;
			}
		}
		if(yes){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}