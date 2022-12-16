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

const int maxn=1e4+10,mod=1e9+7;
const ll inf=1e18;

pii dp[maxn];
pii p[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, l, r, cnt=0; cin>>n>>l>>r;
    for(int i=0; i<n; i++){
	cin>>p[i].S;
	p[i].S*=-1;
    }
    for(int i=0; i<n; i++){
	cin>>p[i].F;
	cnt+= p[i].F;
    }
    sort(p,p+n);

    fill(dp, dp+maxn, (pii){-1,0});
    dp[0]={0,0};
    for(int i=0; i<n; i++){
	for(int j=maxn-1; j>=0; j--){
	    if(j + p[i].S >=0 && dp[j + p[i].S].F!=-1)
		dp[j]= max( dp[j], (pii){ dp[j + p[i].S].F + ( l<=j+p[i].S && j+p[i].S<=r && p[i].F ), dp[ j + p[i].S ].S - p[i].F } ); 
	}
    }
    int ans=0;
    for(int i=0; i<maxn; i++){
	ans= max( ans, dp[i].F + (l<=i && i<=r && dp[i].F!=-1 && -dp[i].S<cnt) );
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")