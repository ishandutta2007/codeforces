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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=6010;

#pragma GCC Optimize("Ofast")

pll p[maxn];
ll r[maxn];
vector<ll>v[maxn];
short h=2,ans;
short dp[2][maxn][maxn];// 0 increase // 1 decrease
short tmp[2][maxn];

void dfs(ll u,ll par=-1){
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=par){
			dfs(y,u);
		}
	}
	memset(tmp,0,sizeof tmp);
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(y!=par){
			FOR(j,1,maxn-2){
				ans=max(ans,short(dp[0][y][j]+tmp[1][j+1]));
				ans=max(ans,short(dp[1][y][j]+tmp[0][j-1]));
			}
			ans=max(ans,short(1+dp[0][y][r[u]]+tmp[1][r[u]]));
			ans=max(ans,short(1+dp[1][y][r[u]]+tmp[0][r[u]]));
			FOR(j,1,maxn-2){
				tmp[0][j]=max(tmp[0][j],(dp[0][y][j]));
				tmp[1][j]=max(tmp[1][j],(dp[1][y][j]));
			}
		}
	}
	FOR(i,1,maxn-2){
		dp[0][u][i]=max(tmp[0][i],short(r[u]>i?1+tmp[0][r[u]]:(0)));
		dp[1][u][i]=max(tmp[1][i],short(r[u]<i?1+tmp[1][r[u]]:(0)));
		ans=max(ans,(dp[0][u][i]));
	}
}
int main(){
	// input
	ll n;cin>>n;
	REP(i,n){
		cin>>p[i].F;
		p[i].S=i;
	}
	sort(p,p+n);
	ll i=0;
	while(i<n){
		int bef=p[i].F;
		while(i<n&&p[i].F==bef){
			r[p[i].S]=h;
			i++;
		}
		h++;
	}
	REP(i,n-1){
		ll a,b;cin>>a>>b;
		a--;b--;
		v[a].PB(b);
		v[b].PB(a);
	}
	// input finished
	dfs(0);
	cout<<ans;
}