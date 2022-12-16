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
const ll maxn=2e5+10;
const ll mod=1e9+7;

int main(){
	string s;cin>>s;
	ll ans=0;
	bool used=0;
	if(s[0]=='K'&&s[1]=='K')used=1;
	if(s[sz(s)-2]=='V'&&s[sz(s)-1]=='V')used=1;
	FOR(i,1,sz(s)-1){
		if(s[i]=='K'&&s[i-1]=='V')ans++;
		if(i>1&&s[i-2]==s[i-1]&&s[i-1]==s[i])used=1;
	}
	cout<<ans+used;
}