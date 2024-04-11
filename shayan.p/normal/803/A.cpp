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

const ll inf=1e18;
const ll maxn=110;
const ll mod=1e9+7;

bool ans[maxn][maxn];
int main(){
	ll n,k;cin>>n>>k;
	REP(i,n){
		ll m;
		if(k==0)continue;
		if(k%2) m=(k+1)/2;
		else m=k/2;
		m=min(n-i,m);
		REP(j,m)ans[i][i+j]=1;
		REP(j,m)ans[i+j][i]=1;
		k=k-(2*m)+1;
	}
	if(k>0){
		cout<<-1;
		return 0;
	}
	REP(i,n){
		REP(j,n){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}