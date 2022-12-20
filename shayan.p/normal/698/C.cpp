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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)
#define Bug(num) cout<<"here "<<num<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=21;
const ll MASK=11e5;
const ll mod=1e9+7;
const ll inf=4e18;

ll n,k;
ld p[maxn],dp[MASK],ans[maxn];

int main(){
	ll n,k;cin>>n>>k;
	REP(i,n)
		cin>>p[i];
	REP(msk,(1<<n)){
		ld P=0;
		REP(i,n){
			if(bit(msk,i)){
				P+=p[i];
			}
		}
		if(P==1)
			dp[msk]=inf;
		else
			dp[msk]=(1/(1-P));
	}
	FORD(i,n-1,0){
		REP(msk,(1<<n)){
			if(bit(msk,i))
				dp[msk]-=dp[msk^(1<<i)];
		}
	}
	REP(i,n){
		REP(msk,(1<<n)){
			ll num=__builtin_popcount(int(msk));
			if(num>=k)continue;
			if(!bit(msk,i)){
				ans[i]+=dp[msk];
			}
		}
		ans[i]=ans[i]*p[i];
	}
	REP(i,n)
		cout<<setprecision(9)<<fixed<<ans[i]<<" ";
}