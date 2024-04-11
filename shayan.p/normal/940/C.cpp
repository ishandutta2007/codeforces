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
const ll mod=1e9+7;
const ll maxn=2e5+10;

set<char>st;

int main(){
	ll n,k;cin>>n>>k;
	string s;cin>>s;
	REP(i,n)
		st.insert(s[i]);
	if(n<k){
		cout<<s;
		REP(i,k-n)
			cout<<*st.begin();
		return 0;
	}
	ll pos;
	REP(i,k){
		if(s[i]!=*st.rbegin())
			pos=i;
	}
	FOR(i,0,pos-1)
		cout<<s[i];
	cout<<*(++st.find(s[pos]));
	FOR(i,pos+1,k-1)
		cout<<*st.begin();
}