// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
bool mark[maxn];

int dfs(int u){
    mark[u]=1;
    int ans=1;
    for(int y:v[u]){
	if(!mark[y])
	    ans+=dfs(y);
    }
    return ans;
}

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod){
	if(b&1)
	    ans=1ll*ans*a %mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=0;i<n-1;i++){
	int a,b,x;cin>>a>>b>>x;
	if(x==1) continue;
	v[a].PB(b);
	v[b].PB(a);
    }
    int ans=Pow(n,k);
    for(int i=1;i<=n;i++){
	if(!mark[i])
	    ans=(ans-Pow(dfs(i),k))%mod;
    }
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
		 
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.