// new day,new strength,new thougts

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
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=18;
const ll maxn2=266;
const ll MASK=65546;

#pragma GCC Optimize("Ofast")

char c[maxn];
ll r[maxn],b[maxn];

ll dp[MASK][maxn2];

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>c[i]>>r[i]>>b[i];
	REP(i,maxn2)
		dp[0][i]=-1;// impossible
	dp[0][0]=0;
	FOR(i,1,((1<<n)-1)){
		ll B=0,R=0;
		REP(k,n){
			if(bit(i,k))
				(c[k]=='R'?R:B)++;
		}
		REP(j,maxn2){
			dp[i][j]=-1;
			REP(k,n){
				if(bit(i,k)){
					ll numr=min(r[k],R-(c[k]=='R')),numb=min(b[k],B-(c[k]=='B'));
					if(j<numr)continue;
					if(dp[i^(1<<k)][j-numr]==-1)continue;
					dp[i][j]=max(dp[i][j],dp[i^(1<<k)][j-numr]+numb);
				}
			}
		}
	}
	ll ans=inf;
	ll B=0,R=0;
	REP(i,n){
		B+=b[i];R+=r[i];
	}
	REP(r,maxn2){
		ll b=dp[(1<<n)-1][r];
		if(b==-1)continue;
		ans=min(ans,max(B-b,R-r)+n);
	}
	cout<<ans;
}