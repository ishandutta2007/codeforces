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

ll f[10],s[10];

int main(){
	ll n;cin>>n;
	string s1,s2;cin>>s1>>s2;
	REP(i,sz(s1))
		f[s1[i]-'0']++;
	REP(i,sz(s2))
		s[s2[i]-'0']++;
		
	ll copf[10],cops[10];
	REP(i,10){
		copf[i]=f[i];
		cops[i]=s[i];
	}
	ll ans1=0,ans2=0;
	REP(i,10){
		ll now=i;
		while(now<10&&copf[i]>0){
			ll m=min(copf[i],cops[now]);
			copf[i]-=m;
			cops[now]-=m;
			now++;
		}
		ans1+=copf[i];
	}
	
	REP(i,10){
		copf[i]=f[i];
		cops[i]=s[i];
	}
	REP(i,10){
		ll now=i+1;
		while(now<10&&copf[i]>0){
			ll m=min(copf[i],cops[now]);
			copf[i]-=m;
			cops[now]-=m;
			ans2+=m;
			now++;
		}
	}
	cout<<ans1<<"\n"<<ans2;
}