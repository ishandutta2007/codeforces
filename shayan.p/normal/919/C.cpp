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
const ll maxn=2e3+10;

#pragma GCC Optimize("Ofast")

string s[maxn];
int main(){
	ll n,m,k;cin>>n>>m>>k;
	REP(i,n)
		cin>>s[i];
	vector<ll>v;
	REP(i,n){
		ll num=0;
		REP(j,m){
			if(s[i][j]=='*'){
				v.PB(num);
				num=0;
			}
			else{
				num++;
			}
		}
		v.PB(num);
	}
	if(k!=1){
		REP(j,m){
			ll num=0;
			REP(i,n){
				if(s[i][j]=='*'){
					v.PB(num);
					num=0;
				}
				else{
					num++;
				}
			}
			v.PB(num);
		}
	}
	ll ans=0;
	REP(i,sz(v)){
		if(v[i]>=k){
			ans+=v[i]-k+1;
		}
	}
	cout<<ans;
}