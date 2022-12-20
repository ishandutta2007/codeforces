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

const int maxn=1e5+10,maxc=11,mod=1e9+7;

int n,m,k,c;
ll dp[maxn][maxc][3],arr[maxc][3];
vector<int>v[maxn];

void dfs(int u,int par=-1){
    for(int y:v[u]){
	if(y!=par){
	    dfs(y,u);
	}
    }
    dp[u][0][0]=k-1;
    dp[u][1][1]=1;
    dp[u][0][2]=m-k;
    for(int y:v[u]){
	if(y!=par){
	    memset(arr,0,sizeof arr);
	    for(int j=c;j>=0;j--){
		for(int i=0;i<=j;i++){
		    arr[j][0]=(arr[j][0]+dp[u][j-i][0]*(dp[y][i][0]+dp[y][i][1]+dp[y][i][2])) %mod;
		    arr[j][1]=(arr[j][1]+dp[u][j-i][1]*(dp[y][i][0])) %mod;
		    arr[j][2]=(arr[j][2]+dp[u][j-i][2]*(dp[y][i][0]+dp[y][i][2])) %mod;
		}
	    }
	    for(int i=0;i<maxc;i++)
		for(int j=0;j<3;j++)
		    dp[u][i][j]=arr[i][j];
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    cin>>k>>c;
    dfs(1);
    ll ans=0;
    for(int i=0;i<=c;i++)
	for(int j=0;j<3;j++)
	    ans=(ans+dp[1][i][j])%mod;
    cout<<ans<<endl;
    return 0;
}