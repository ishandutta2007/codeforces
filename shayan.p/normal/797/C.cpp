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

char Min[maxn];

int main(){
	string s;cin>>s;
	stack<char>st;
	Min[sz(s)]='z';
	REPD(i,sz(s)){
		Min[i]=min(s[i],Min[i+1]);
	}
	vector<char>targ;
	ll now=0;
	while(now<sz(s)){
		if(st.empty()||Min[now]<st.top())
			st.push(s[now++]);
		else{
			targ.PB(st.top());
			st.pop();
		}
	}
	while(sz(st)){
		targ.PB(st.top());
		st.pop();
	}
	REP(i,sz(targ))
		cout<<targ[i];
}