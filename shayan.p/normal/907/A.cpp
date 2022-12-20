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

int main(){
	ll v1,v2,v3,vm;cin>>v1>>v2>>v3>>vm;
	FOR(c1,v1,2*v1){
		FOR(c2,v2,2*v2){
			FOR(c3,v3,2*v3){
				if(c1>c2&&c2>c3&&vm<=c3&&2*vm>=c3&&2*vm<c1&&2*vm<c2){
					cout<<c1<<endl<<c2<<endl<<c3;
					return 0;
				}
			}
		}
	}
	cout<<-1;
	return 0;
}