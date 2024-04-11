// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

const ll inf=1e18;
const ll maxn=1e5+10,SQRT=31623;

ll s[maxn][12],ans;
vector<pll>p;

int main(){
	ll n,k;cin>>n>>k;
	ll cop=k;
	FOR(i,2,SQRT){
		ll num=0;
		while(cop%i==0){
			cop/=i;
			num++;
		}
		if(num!=0){
			p.PB(MP(i,num));
		}
	}
	if(cop>1){
		p.PB(MP(cop,1));
	}
	FOR(i,1,n){
		ll x;cin>>x;
		REP(j,sz(p)){
			ll num=0;
			while(x%p[j].F==0){
				x/=p[j].F;
				num++;
			}
			s[i][j]=s[i-1][j]+num;
		}
	}
	if(k==1){
		cout<<((n*(n-1))/2)+n;
		return 0;
	}
	FOR(i,1,n){
		ll m=0,tmp;
		REP(j,sz(p)){
			ll l=1,r=n;
			tmp=n+1;
			while(l<=r){
				ll mid=(l+r)/2;
				if(s[mid][j]-s[i-1][j]>=p[j].S){
					tmp=mid;
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			m=max(m,tmp);
		}
		ans+=n-m+1;
	}
	cout<<ans;
}