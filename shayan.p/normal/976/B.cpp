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
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

int main(){
	ll n,m,k;cin>>n>>m>>k;
	k++;
	if(k<=n){
		cout<<k<<" "<<1;
		return 0;
	}
	k-=n;
	m--;
	ll a=n-((k-1)/m);
	ll b=k%(2*m);
	if(b==0||b==1)
		b=2;
	else if(b<=m)
		b=1+b;
	else
		b=1+m+1-(b-m);
	cout<<a<<" "<<b;
}