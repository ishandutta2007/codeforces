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

ll a[maxn];
set<ll>st;
stack<ll>s;
int main(){
	ll n,k;cin>>n>>k;
	REP(i,k)
		cin>>a[i];
	FOR(i,1,n)
		st.insert(i);
	ll looking_for=1;
	REP(i,n){
		if(i>=k){
			if(s.empty()){
				a[i]=*(--st.end());
			}
			else{
				set<ll>::iterator it=--st.upper_bound(s.top());//what happens if it is --it.begin()?
				a[i]=*it;
			}
		}
		if(!s.empty()&&a[i]>s.top()){
			cout<<-1;
			return 0;
		}
		st.erase(a[i]);
		s.push(a[i]);
		while(sz(s)&&looking_for==s.top()){
			s.pop();
			looking_for++;
		}
		while(sz(s)&&looking_for==s.top()){
			s.pop();
			looking_for++;
		}
	}
	if(looking_for==n+1){
		REP(i,n){
			cout<<a[i]<<" ";
		}
	}
	else{
		cout<<-1;
	}
	return 0;
}