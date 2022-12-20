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

set<ll>Set;
stack<ll>Stack;

int main(){
	ll n;cin>>n;
	ll h=1,ans=0;
	REP(i,2*n){
		string s;cin>>s;
		if(s=="remove"){
			if(Stack.empty()){
				Set.erase(h);
			}
			else if(Stack.top()==h){
				Stack.pop();
			}
			else{
				ans++;
				while(sz(Stack)){
					Set.insert(Stack.top());
					Stack.pop();
				}
				Set.erase(h);
			}
			h++;
		}
		else{
			ll t;cin>>t;
			Stack.push(t);
		}
	}
	cout<<ans;
}