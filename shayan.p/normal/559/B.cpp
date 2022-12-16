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

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

string f(string s,ll l,ll r){
	if((r-l)%2)return s;
	ll ln=(r-l)/2;
	string s1=f(s.substr(0,ln),l,l+ln),s2=f(s.substr(ln,ln),l+ln,r);
	if(s1>s2)swap(s1,s2);
	return (s1+s2);
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	s1=f(s1,0,sz(s1));
	s2=f(s2,0,sz(s2));
	cout<<(s1==s2?"YES":"NO");
}