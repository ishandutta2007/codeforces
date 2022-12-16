// Phoenix

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

vector<int>v[maxn];
ll a[maxn],dp[maxn],mx=-inf;
int cnt=0;

void dfs(int u,int par=-1){
    dp[u]=a[u];
    for(int y:v[u]){
	if(y!=par){
	    dfs(y,u);
	    if(dp[y]>0)
		dp[u]+=dp[y];
	}
    }
}

void dfs2(int u,int par=-1){
    dp[u]=a[u];
    for(int y:v[u]){
	if(y!=par){
	    dfs2(y,u);
	    if(dp[y]>0)
		dp[u]+=dp[y];
	}
    }
    if(dp[u]==mx)
	cnt++,dp[u]=-inf;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    for(int i=1;i<n;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
	mx=max(mx,dp[i]);
    dfs2(1);
    cout<<mx*cnt<<" "<<cnt<<endl;
    return 0;
}