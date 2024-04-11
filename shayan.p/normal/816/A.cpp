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

string to_str(ll num){
	stringstream stream;stream<<num;
	string s;stream>>s;
	return s;
}
ll to_ll(string s){
	stringstream stream;stream<<s;
	ll num;stream>>num;
	return num;
}
ll pal(ll num){
	return 10*(num%10)+num/10;
}
ll f(ll a,ll b){
	if(pal(a)>=b){
		if(pal(a)<60)return pal(a)-b;
		else 60-b+f((a+1)%24,0);
	}
	return 60-b+f((a+1)%24,0);
}
int main(){
	string s;cin>>s;
	ll a=to_ll(s.substr(0,2));
	ll b=to_ll(s.substr(3,2));
	cout<<f(a,b);
}