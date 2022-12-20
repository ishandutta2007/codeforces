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
const ll maxn=52;

ll a[maxn][maxn];
int main(){
	ll n;cin>>n;
	REP(i,n){
		REP(j,n){
			cin>>a[i][j];
		}
	}
	REP(i,n){
		REP(j,n){
			if(a[i][j]==1)
				continue;
			bool yes=0;
			REP(s,n){
				REP(t,n){
					if(a[i][s]+a[t][j]==a[i][j]){
						yes=1;
					}
				}
			}
			if(!yes){
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
}