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
const ll maxn=2e5+10;
const ll mod=1e9+7;
const ll Max=6e6+10;

#pragma GCC Optimize("Ofast")

vector<ll>bt[61];
vector<ll>ans[61];
ll ones[61];

int main(){
	ll n;cin>>n;
	REP(i,n){
		ll x;cin>>x;
		ll lst;
		REP(j,60){
			if(bit(x,j)){
				lst=j;
				ones[j]++;
			}
		}
		bt[lst].PB(x);
	}
	REPD(i,60){
		if((1+ones[i])<(2*sz(bt[i]))){
			cout<<"No";
			return 0;
		}
		if(sz(bt[i])==0){
			ans[i]=ans[i+1];
			continue;
		}
		ll pt=1;
		ans[i].PB(bt[i][0]);
		REP(j,sz(ans[i+1])){
			ans[i].PB(ans[i+1][j]);
			if(bit(ans[i+1][j],i)&&pt!=sz(bt[i]))
				ans[i].PB(bt[i][pt++]);
		}
	}
	cout<<"Yes\n";
	REP(i,sz(ans[0]))
		cout<<ans[0][i]<<" ";
}