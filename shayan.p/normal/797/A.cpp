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

int main(){
	ll n,k;cin>>n>>k;
	ll N=n;
	vector<ll>v;
	FOR(i,2,n){
		while(N%i==0){
			v.PB(i);
			N/=i;
		}
	}
	if(sz(v)<k){
		cout<<-1;
	}
	else{
		REP(i,k-1){
			cout<<v[i]<<" ";
			n/=v[i];
		}
		cout<<n;
	}
}