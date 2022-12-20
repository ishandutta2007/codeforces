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
const ll maxn=1e5+10;
const ll BIG=5e4;

ll x,y,p;
vector<ll>v;

bool pos(ll num){
	ll i=((num/50)%475);
	REP(j,25){
		i=((i*96+42)%475);
		if((26+i)==p)return 1;
	}
	return 0;
}

int main(){
	cin>>p>>x>>y;
	FOR(i,y,y+BIG){
		if(pos(i))
			v.PB(i);
	}
	ll ans=inf;
	REP(i,sz(v)){
		if((v[i]%50)!=(x%50))continue;
		if(v[i]>=x){
			ll num=((v[i]-x)/50);
			ans=min(ans,((num/2)+(num%2)));
		}
		else{
			ans=0;
		}
	}
	cout<<ans;
}