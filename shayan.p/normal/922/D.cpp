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

pll p[maxn];
bool cmp(pll a,pll b){
	return (a.F*b.S)>(a.S*b.F);
}
ll ans;
ll tot;

int main(){
	ll n;cin>>n;
	REP(i,n){
		string s;cin>>s;
		ll a=0,b=0;
		REP(j,sz(s)){
			if(s[j]=='s')
				a++;
			else
				b++;
		}
		p[i]=MP(a,b);
		tot+=b;
		REP(j,sz(s)){
			if(s[j]=='s'){
				a--;
				ans+=b;
			}
			else{
				b--;
			}
		}
	}
	sort(p,p+n,cmp);
	REP(i,n){
		tot-=p[i].S;
		ans+=(p[i].F*tot);
	}
	cout<<ans;
}