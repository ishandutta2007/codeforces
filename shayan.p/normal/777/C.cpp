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
const ll MAX=1e5+10;

#pragma GCC Optimize("Ofast")

ll mx[MAX];
pll seg[MAX];
ll h;

int main(){
	ll n,m;cin>>n>>m;
	ll a[n+10][m+10];
	REP(i,n)
		REP(j,m)
			cin>>a[i][j];
			
	REP(j,m)
		a[n][j]=-inf;
		
	REP(j,m){
		ll i=0,bef=0;
		while(i<n){
			while(i<n&&a[i][j]<=a[i+1][j])
				i++;
			seg[h++]=MP(bef,i);
			i++;
			bef=i;
		}
	}
	sort(seg,seg+h);
	REP(i,h){
		mx[i]=max((i==0?-inf:mx[i-1]),seg[i].S);
	}
	
	ll k;cin>>k;
	REP(i,k){
		ll f,s;cin>>f>>s;
		f--;s--;
		ll l=0,r=h-1,ans;
		while(l<=r){
			ll mid=(l+r)/2;
			if(seg[mid].F<=f){
				ans=mx[mid];
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		if(ans>=s)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}