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
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

string s;

bool pal(ll i,ll j){
	FOR(k,i,j){
		if(s[k]!=s[i+j-k])
			return 0;
	}
	return 1;
}

int main(){
	cin>>s;
	ll ans=0;
	FOR(i,0,sz(s)-1){
		FOR(j,i,sz(s)-1){
			if(!pal(i,j))
				ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
}