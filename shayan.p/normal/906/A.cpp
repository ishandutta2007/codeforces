// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

set<char>st;
ll ans=0;

int main(){
	FOR(i,'a','z')
		st.insert(char(i));
	ll n;cin>>n;
	REP(i,n){
		char ch;cin>>ch;
		string s;cin>>s;
		if(i==n-1)
			continue;
		if(ch=='!'){
			if(st.size()==1){
				ans++;
			}
			set<char>st2;st2.clear();
			FOR(i,'a','z')
				st2.insert(char(i));
			REP(j,sz(s))
				st2.erase(s[j]);
			for(set<char>::iterator it=st2.begin();it!=st2.end();it++){
				st.erase(*it);
			}
		}
		if(ch=='.'){
			set<char>st2;
			st2.clear();
			REP(j,sz(s))
				st2.insert(s[j]);
			for(set<char>::iterator it=st2.begin();it!=st2.end();it++){
				st.erase(*it);
			}
		}
		if(ch=='?'){
			if(st.size()==1){
				ans++;
			}
			st.erase(s[0]);
		}
	}
	cout<<ans;
}