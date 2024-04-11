#include<bits/stdc++.h>
#define PB push_back
#define PF push_front
#define POF pop_front
#define POB pop_back
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define REP(i,a) for(ll i=0;i<a;i++)
#define REPD(i,a) for(ll i=a-1;i>=0;i--)
#define MP make_pair
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll ind=1e18;
const ll maxn=2e5+10;

int main(){
	ll n;cin>>n;
	ll N=n/2;
	if(n%2){
		cout<<(N+1)*(N+1);
	}
	else{
		cout<<N*(N+1);
	}
}