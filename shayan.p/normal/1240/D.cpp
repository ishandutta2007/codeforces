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
 
const int maxn=3e5+10;

map<int,int> mp[maxn];
int f[maxn], a[maxn];
ll dp[maxn], ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;
    
    while(q--){
	int n; cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    mp[i].clear();
	}
	dp[0]=0, f[0]=-1, ans=0;
	
	for(int i=1;i<=n;i++){
	    if(mp[i-1].count(a[i]))
		f[i]= mp[i-1][a[i]]-1,  swap(mp[ f[i] ], mp[i] ), mp[i][a[i]]=i, dp[i]= 1 + dp[f[i]];
	    else
		f[i]= -1, mp[i][a[i]]=i, dp[i]=0;
	    ans+= dp[i];
	}
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