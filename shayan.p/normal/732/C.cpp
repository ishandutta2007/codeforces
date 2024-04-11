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

const ll inf=3e18;
const ll mod=1e9+7;
const ll maxn=2e5+10;

int main(){
	ll a,b,c;cin>>a>>b>>c;
	ll ans=inf;
	REP(i,3){
		REP(j,3){
			ll day,A,B,C;
			A=a+(i>0)+(j<0);
			B=b+(i>1)+(j<1);
			C=c+(i>2)+(j<2);
			day=max(A,max(B,C));
			ll num=day*3-i-(2-j);
			ans=min(ans,num-a-b-c);
		}
	}
	cout<<ans;
}