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

const ll inf=1e17;
const ll maxn=5010;

#pragma GCC Optimize("Ofast")

ll dp[maxn][maxn],cnt[maxn];
vector<ll>v[maxn];

ll dfs(ll u,ll p=-1){
	REP(i,maxn)
		dp[u][i]=inf;
	dp[u][0]=0;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=p){
			dfs(y,u);
			cnt[u]+=cnt[y];
			FORD(q,cnt[u],0){// cause we are moving backward information from previous time does not damage
				FOR(w,0,min(q,cnt[y])){
					ll A=dp[u][q-w]+dp[y][w];// the son has the same color
					ll B=dp[u][q-w]+dp[y][cnt[y]-w]+1;// the son has different color 
					dp[u][q]=min(dp[u][q],min(A,B));
				}
			}
		}
	}
	cnt[u]+=(sz(v[u])==1);
}

int main(){
	ll n;cin>>n;
	REP(i,n-1){
		ll a,b;cin>>a>>b;
		a--;b--;
		v[a].PB(b);
		v[b].PB(a);
	}
	ll r=-1;
	REP(i,n){
		if(sz(v[i])!=1)
			r=i;
	}
	if(r==-1){// all of them are root
		cout<<1;
		return 0;
	}
	dfs(r);
	cout<<dp[r][cnt[r]/2];
}