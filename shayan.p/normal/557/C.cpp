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

const ll inf=4e18;
const ll mod=1e9+7;
const ll maxn=1e5+10;
const ll maxd=210;

ll sm[maxn];
ll cnt[maxd];
pll p[maxn];

ll check(ll ind,ll t){
	ll m=ind+1-t-t+1,sum=0;
	REP(j,maxd){
		ll Min=max(ll(0),min(m,cnt[j]));
		m-=Min;
		sum+=j*Min;
	}
	sum+=sm[ind+1];
	return sum;
}

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>p[i].F;
	REP(i,n)
		cin>>p[i].S;
	sort(p,p+n);
	REPD(i,n)
		sm[i]=sm[i+1]+p[i].S;
	
	ll ans=inf;
	ll lst=p[0].F;
	stack<ll>s;
	REP(i,n){
		if(p[i].F!=lst){
			ans=min(ans,check(i-1,sz(s)));
			while(sz(s)){
				cnt[s.top()]++;
				s.pop();
			}
		}
		lst=p[i].F;
		s.push(p[i].S);
	}
	ans=min(ans,check(n-1,sz(s)));
	cout<<ans;
}