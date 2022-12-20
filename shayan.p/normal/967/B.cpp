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
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll s[maxn];
ll S;

int main(){
	ll n,A,B;cin>>n>>A>>B;
	REP(i,n){
		cin>>s[i];
		S+=s[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	sort(s+1,s+n,greater<ll>());
	ll ans=0;
	FOR(i,1,n-1){
		if((s[0]*A)>=(B*S))
			break;
		ans++;
		S-=s[i];
	}
	cout<<ans;
}