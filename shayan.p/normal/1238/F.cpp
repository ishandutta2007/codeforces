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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int> v[maxn];
int dp[maxn], ans;

void dfs(int u,int par=-1){
    int A=-1, B=-1;
    for(int y:v[u]){
	if(y!=par){
	    dfs(y,u);
	    if(dp[y]>A) B=A, A=dp[y];
	    else if(dp[y]>B) B=dp[y];
	}
    }
    if(A==-1){
	dp[u]= sz(v[u])-1;
    }
    else{
	dp[u]= sz(v[u])-1 + A;
    }
    ans=max(ans, dp[u]+2 );
    if(A!=-1 && B!=-1){
	ans=max(ans, A+B+sz(v[u])+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;
    while(q--){
	int n; cin>>n;
	for(int i=1;i<=n;i++){
	    v[i].clear();
	}
	for(int i=0;i<n-1;i++){
	    int a,b; cin>>a>>b;
	    v[a].PB(b);
	    v[b].PB(a);
	}
	ans=0;
	dfs(1);
	cout<<ans<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")