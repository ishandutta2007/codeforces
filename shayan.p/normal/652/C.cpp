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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=3e5+10;

#pragma GCC Optimize("Ofast")

ll a[maxn];
vector<ll> fo[maxn];
ll is[maxn];

int main(){
	ll n,m;scanf("%d%d",&n,&m);
	REP(i,n)
		scanf("%d",&a[i]);
	REP(i,m){
		ll x,y;scanf("%d%d",&x,&y);
		fo[x].PB(y);
		fo[y].PB(x);
	}
	ll r=0,now=0;
	long long ans=0;
	REP(l,n){
		bool yes=1;
		while(r<n&&yes){
			ll j=now;
			while(j<sz(fo[a[r]])){
				now=j;
				if(is[fo[a[r]][j]]){
					yes=0;
					break;
				}
				j++;
			}
			if(yes){
				now=0;
				is[a[r]]++;
				r++;
			}
		}
		ans+=r-l;
		is[a[l]]--;
	}
	cout<<ans;
	
}