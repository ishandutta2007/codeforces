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

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxn=1e6+10;

#pragma GCC Optimize("Ofast")

ll arr[2*maxn];
ll bef;

int main(){
	ll n;cin>>n;
	REP(i,n)
		arr[i]=i;
	FOR(i,2,n){
		arr[bef+n]=arr[bef+n-(n%i)];
		FORD(j,(n/i),1)
			arr[bef+(j*i)]=arr[bef+(j*i)-i];
		bef++;
	}
	REP(i,n)
		cout<<arr[bef+i]+1<<" ";
}