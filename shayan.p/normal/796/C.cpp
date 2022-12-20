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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=2e9;
const ll maxn=3e5+10;

ll a[maxn];
vector<ll>v[maxn];
map<ll,ll>mp;

int main(){
	ll n;scanf("%d",&n);
	REP(i,n){
		scanf("%d",&a[i]);
		mp[a[i]+2]++;
	}
	REP(i,n-1){
		ll A,B;scanf("%d%d",&A,&B);
		A--;B--;
		v[A].PB(B);
		v[B].PB(A);
	}
	ll ans=inf;
	REP(i,n){
		if(--mp[a[i]+2]==0)mp.erase(a[i]+2);
		mp[a[i]]++;
		REP(j,sz(v[i])){
			ll y=v[i][j];
			if(--mp[a[y]+2]==0)mp.erase(a[y]+2);
			mp[a[y]+1]++;
		}
		
		ans=min(ans,mp.rbegin()->F);
		
		if(--mp[a[i]]==0)mp.erase(a[i]);
		mp[a[i]+2]++;
		REP(j,sz(v[i])){
			ll y=v[i][j];
			if(--mp[a[y]+1]==0)mp.erase(a[y]+1);
			mp[a[y]+2]++;
		}
	}
	cout<<ans;
}