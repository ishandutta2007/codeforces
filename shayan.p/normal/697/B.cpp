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

#pragma GCC Optimize("Ofast")

ll to_ll(string s){
	stringstream stream;stream<<s;
	ll num;stream>>num;
	return num;
}

string to_str(ll num){
	stringstream stream;stream<<num;
	string s;stream>>s;
	return s;
}


int main(){
	string s;cin>>s;
	ll E;
	REP(i,sz(s))
		if(s[i]=='e')
			E=i;
	string a=s.substr(0,1);
	string b=s.substr(2,E-2);
	ll d=to_ll(s.substr(E+1));
	REP(i,200)
		b+="0";
	FORD(i,sz(b)-1,d+1)
		b[i]=b[i-1];
	b[d]='.';
	ll last;
	REPD(i,sz(b)){
		if(b[i]!='0'){
			last=i;
			break;
		}
	}
	if(b[last]=='.')
		last--;
	cout<<a<<b.substr(0,last+1);
}