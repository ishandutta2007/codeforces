// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e6+10, maxM=11;
const ll inf=1e18;

pll p[maxn];
vector<ll> prm;

int cnt[1<<maxM], ctz[1<<maxM], popc[1<<maxM];
ll zr[1<<maxM], vl[maxM];

vector<int> upd[maxn];

ll dp[maxM+1][1<<maxM];

map<ll,int> mp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; ll k; cin>>n>>k;
    ll g=0;
    for(int i=0;i<n;i++)
	cin>>p[i].S, g=__gcd(g,p[i].S);
    for(int i=0;i<n;i++)
	cin>>p[i].F;
    sort(p,p+n);
    for(ll i=2;i*i<=g;i++){
	if(g%i==0){
	    while(g%i==0) g/=i;
	    prm.PB(i);
	}
    }
    if(g>1){
	prm.PB(g);
    }
    
    int M=sz(prm);
    for(int i=1;i<(1<<M);i++){
	ctz[i]= __builtin_ctz(i);
	popc[i]= __builtin_popcount(i);
    }
    for(int i=0;i<n;i++){
	if(++mp[p[i].S]>M) continue;
	for(int j=0;j<M;j++){
	    vl[j]=1;
	    while(p[i].S % prm[j] == 0) p[i].S/=prm[j], vl[j]*= prm[j];
	}
	zr[0]=1;
	for(int msk=1;msk<(1<<M);msk++){
	    zr[msk]= zr[msk ^ (msk & (-msk))] * vl[ctz[msk]];
	    if(zr[msk]<=k){
		if(++cnt[msk]<=M-popc[msk]+1)
		    upd[i].PB(msk);
	    }
	}
    }

    for(int i=0;i<=M;i++){
	for(int j=1;j<(1<<M);j++)
	    dp[i][j]= inf;
    }
    
    for(int i=0;i<n;i++){
	if(upd[i].empty()) continue;
	for(int j=M;j>=1;j--){
	    for(int msk=1;msk<(1<<M);msk++){
		for(int msk2:upd[i]){
		    if((msk & msk2) == msk2) 
			dp[j][msk]= min( dp[j][msk], dp[j-1][msk ^ msk2] + p[i].F );
		}
	    }
	}
    }
    ll ans=inf;
    for(int i=0;i<=M;i++){
	if(dp[i][(1<<M)-1]!=inf)
	    ans=min(ans, dp[i][(1<<M)-1] * i);
    }
    if(ans==inf) ans=-1;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")