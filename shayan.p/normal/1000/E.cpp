// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=3e5+10;
const ll mod=1e9+7;

vector<ll>v[maxn];
ll dp[maxn],mx[maxn],h[maxn],ans;
bool mark[maxn];

void dfs(ll u,ll par=-1){
    ll mx1=0,mx2=0;
    mark[u]=1;
    dp[u]=h[u];
    for(ll y:v[u]){
	if(mark[y] && y!=par ){
	    dp[u]=min(dp[u],h[y]);
	}
	if(!mark[y]){
	    h[y]=h[u]+1;
	    dfs(y,u);
	    mx[u]=max(mx[u],mx[y]);
	    dp[u]=min(dp[u],dp[y]);
	    if(mx1<mx[y]){
		mx2=mx1;
		mx1=mx[y];
	    }
	    else if(mx2<mx[y]){
		mx2=mx[y];
	    }	
	}
    }
    if(dp[u] == h[u])
	mx[u]++;
    ans=max(ans,mx2+mx1);
}

int main(){
    ll n,m;cin>>n>>m;
    REP(i,m){
	ll a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    cout<<ans;
}