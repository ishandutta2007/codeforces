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
const ll maxn=1e3+10;

ll a[maxn],b[maxn],ans;

int main(){
	ll n;cin>>n;
	REP(i,n)cin>>a[i];
	REP(i,n)cin>>b[i];
	FOR(i,0,n-1){
		ll A=0,B=0;
		FOR(j,i,n-1){
			A|=a[j];
			B|=b[j];
			ans=max(ans,A+B);
		}
	}
	cout<<ans;
}