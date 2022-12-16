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

const ll inf=2e18+100;
const ll maxn=2e5+10;
const ll mod=1e9+7;

vector<ll>p0,p1;
vector<ll>v0,v1;

void go(vector<ll>&v,vector<ll>&p,ll cur,ll i){
	if(i==sz(p)){
		v.PB(cur);
		return;
	}
	if(inf/cur>p[i])
		go(v,p,cur*p[i],i);
	go(v,p,cur,i+1);
}

ll CNT(ll num){
	ll j=sz(v1)-1,ans=0;

	REP(i,sz(v0)){
		while(j>=0&&v1[j]>=inf/v0[i])
			j--;
		while(j>=0&&v1[j]*v0[i]>num)
			j--;
		ans+=j+1;
	}
	return ans;
}

int main(){
	ll n;cin>>n;
	REP(i,n){
		ll x;cin>>x;
		if(i%2)p1.PB(x);
		else p0.PB(x);
	}
	go(v0,p0,1,0);
	go(v1,p1,1,0);
	sort(v0.begin(),v0.end());
	sort(v1.begin(),v1.end());
	
	ll k;cin>>k;
	ll l=0,r=inf,ans=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(CNT(mid)>=k){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
}