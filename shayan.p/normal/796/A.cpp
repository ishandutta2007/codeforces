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
const ll maxn=110;

ll a[maxn];
int main(){
	ll n,m,k;cin>>n>>m>>k;
	m--;
	REP(i,n)
		cin>>a[i];
	ll ans1=inf,ans2=inf;
	FOR(i,m+1,n-1){
		if(a[i]==0)continue;
		if(k>=a[i]){
			ans1=i;
			break;
		}
	}
	FORD(i,m-1,0){
		if(a[i]==0)continue;
		if(k>=a[i]){
			ans2=i;
			break;
		}
	}
	cout<<min(abs(m-ans1),abs(m-ans2))*10;
}