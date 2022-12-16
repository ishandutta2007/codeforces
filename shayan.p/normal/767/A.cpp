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

#pragma GCC Optimize("Ofast")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e5+10;

ll a[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n){
		cin>>a[i];
		a[i]=n+1-a[i];
	}
	ll mx=0;
	ll last=0;
	set<ll>st;
	REP(i,n){
		st.insert(a[i]);
		while(st.count(last+1)){
			st.erase(last+1);
			last++;
			cout<<n+1-last<<" ";
		}
		cout<<endl;
	}
}