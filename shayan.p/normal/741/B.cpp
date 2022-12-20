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
const ll maxn=1010;
const ll mod=1e9+7;

ll dp[maxn];
vector<ll>v[maxn];
ll av[maxn],bv[maxn],wh[maxn];
ll a[maxn],b[maxn];

int main(){
    ll n,m,w;cin>>n>>m>>w;
    FOR(i,1,n){
	cin>>a[i];
    }
    FOR(i,1,n){
	cin>>b[i];
    }
    FOR(i,1,n){
	v[i].PB(i);
	wh[i]=i;
	av[i]=a[i];
	bv[i]=b[i];
    }
    FOR(i,1,m){
	ll x,y;cin>>x>>y;
	if((x=wh[x])!=(y=wh[y])){
	    if(sz(v[x])>sz(v[y]))swap(x,y);
	    for(ll q:v[x]){
		v[y].PB(q);
		wh[q]=y;
		av[y]+=a[q];
		bv[y]+=b[q];
	    }
	    av[x]=0;
	    bv[x]=0;
	}
    }
    
    fill(dp+1,dp+maxn,-1);
    FOR(q,1,n){
	if(av[q]==0)continue;
	FORD(i,w,1){
	    ll x=i-av[q];
	    if(x>=0 && dp[x]!=-1)
		dp[i]=max(dp[i],dp[x]+bv[q]);
	    for(ll y:v[q]){
		ll x=i-a[y];
		if(x>=0 && dp[x]!=-1)
		    dp[i]=max(dp[i],dp[x]+b[y]);
	    }
	}
    }
    ll ans=0;
    FOR(i,1,w){
	ans=max(ans,dp[i]);
    }
    cout<<ans;
}