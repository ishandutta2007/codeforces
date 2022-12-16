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
const ll Big=1e6;
const ll tw=1e12+1;

vector<ll>v;

void print(ll div,ll k,ll sum){
	FOR(i,1,k-1){
		cout<<div*i<<" ";
		sum-=i;
	}
	cout<<sum*div;
}
int main(){
	ll n,k;cin>>n>>k;
	if(k>Big){
		cout<<-1;
		return 0;
	}
	FOR(i,1,sqrt(n)){
		if(n%i==0)
			v.PB(i);
	}
	ll Sz=sz(v)-1;
	FORD(i,Sz,0){
		v.PB(n/v[i]);
	}
	ll num=(k*(k+1))/2;
	REPD(i,sz(v)){
		if((tw/num)<=v[i])continue;
		if(num*v[i]<=n){
			print(v[i],k,n/v[i]);
			return 0;
		}
	}
	cout<<-1;
	return 0;
}