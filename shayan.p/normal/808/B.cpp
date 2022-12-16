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

#pragma GCC optimize("Ofast")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll inf=1e18;
const ll maxn=2e5+10;

ll a[maxn];

int main(){
	ll n,k;cin>>n>>k;
	ll sum=0;
	REP(i,n)
		cin>>a[i];
	ll num=0;
	REP(i,k)num+=a[i];
	sum+=num;
	FOR(i,k,n-1){
		num+=a[i];
		if(i-k>=0)num-=a[i-k];
		sum+=num;
	}
	cout<<setprecision(9)<<fixed<<double(sum)/double(n-k+1);
}