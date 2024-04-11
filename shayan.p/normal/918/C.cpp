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
const ll maxn=5010;

#pragma GCC Optimize("Ofast")

int main(){
	string s;cin>>s;
	ll n=sz(s);
	ll ans=0;
	FOR(i,0,n-1){
		pll dp=MP(0,0);
		FOR(j,i,n-1){
			if(s[j]==')'){
				if(dp.S==0)
					break;
				dp.S--;
				if(dp.F==0)
					dp.F=1;
				else
					dp.F--;
			}
			if(s[j]=='('){
				dp.S++;
				dp.F++;
			}
			if(s[j]=='?'){
				dp.S++;
				if(dp.F==0)
					dp.F=1;
				else
					dp.F--;
			}
			if((dp.S%2)==0&&dp.F<=0&&0<=dp.S)
				ans++;
		}
	}
	cout<<ans;
}