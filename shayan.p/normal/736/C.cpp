// Can U hack it?

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

const int maxn=110,maxk=25,mod=1e9+7;

int dp[maxn][maxk][maxk],tmp[maxk][maxk],n,k;// raas // avalin sefid pooshide nashode // balatarin siah
vector<int>v[maxn];

void dfs(int u,int par=-1){
    dp[u][1][k+1]=1;
    for(int y:v[u]){
	if(y!=par){
	    dfs(y,u);
	    memset(tmp,0,sizeof tmp);
	    for(int i0=0;i0<=k+1;i0++){
		for(int j0=0;j0<=k+1;j0++){
		    for(int i1=0;i1<=k+1;i1++){
			for(int j1=0;j1<=k+1;j1++){
			    int A=((i0+j1)<=k||(i0==0))?(0):(i0);
			    int B=((j0+i1)<=k||(i1==0))?(0):(i1+1);
			    if(max(A,B)>k)continue;
			    int &DP=tmp[max(A,B)][min(min(j0,j1+1),k+1)];
			    DP=(1ll*DP+1ll*dp[u][i0][j0]*dp[y][i1][j1])%mod;
			}
		    }
		}
	    }
	    for(int i=0;i<maxk;i++)
		for(int j=0;j<maxk;j++)
		    dp[u][i][j]=tmp[i][j];
	}
    }
    int NUM=1;
    for(int y:v[u]){
	if(y!=par){
	    int num=0;
	    for(int i=0;i<=k;i++)
		for(int j=0;j<=k+1;j++)
		    num=(num+dp[y][i][j])%mod;
	    NUM=(1ll*NUM*num)%mod;
	}
    }
    dp[u][0][0]=(NUM+dp[u][0][0])%mod;
}

int main(){
    cin>>n>>k;
    for(int i=2;i<=n;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    int ans=0;
    for(int i=0;i<=k+1;i++)
	ans=(ans+dp[1][0][i])%mod;
    cout<<ans<<endl;
    return 0;
}