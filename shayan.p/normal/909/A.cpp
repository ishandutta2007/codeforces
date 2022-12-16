#include<bits/stdc++.h>
#define PB push_back
#define PF push_front
#define POF pop_front
#define POB pop_back
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define REP(i,a) for(ll i=0;i<a;i++)
#define REPD(i,a) for(ll i=a-1;i>=0;i--)
#define sz(s) (s.size())
#define MP make_pair
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll ind=1e18;
const ll maxn=2e5+10;

int main(){
	string s1,s2;cin>>s1>>s2;
	cout<<s1[0];
	FOR(i,1,sz(s1)-1){
		if(s1[i]>=s2[0]){
			cout<<s2[0];
			return 0;
		}
		cout<<s1[i];
	}
	cout<<s2[0];
	return 0;
}