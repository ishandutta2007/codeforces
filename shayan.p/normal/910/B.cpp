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
const ll maxn=2e5+10;

ll sum[10];
int main(){
	vector<ll>v;
	ll n,a,b;cin>>n>>a>>b;
	ll ans=inf;
	REP(i1,6)
		REP(i2,6)
			REP(i3,6)
				REP(i4,6)
					REP(i5,6)
						REP(i6,6){
							memset(sum,0,sizeof sum);
							sum[i1]+=a;
							sum[i2]+=a;
							sum[i3]+=a;
							sum[i4]+=a;
							sum[i5]+=b;
							sum[i6]+=b;
							bool yes=1;
							ll num=0;
							REP(q,6){
								if(sum[q]>0)
									num++;
								if(sum[q]>n){
									yes=0;
									break;
								}
							}
							if(yes){
								ans=min(ans,num);
							}
						}
	cout<<ans;
}