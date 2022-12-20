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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
int dp[maxn],dp2[maxn],a[maxn];
bool is[maxn],is2[maxn];
bool mark[maxn];
int ANS;

void dfs1(int u,int par=-1){
    if(mark[u]){
	is[u]=1;dp[u]=0;
	for(int y:v[u])
	    if(y!=par)
		dfs1(y,u);
	return;
    }
    mark[u]=1;
    is[u]=0;dp[u]=1;
    int mx=-1;
    for(int y:v[u]){
	if(y!=par){
	    dfs1(y,u);
	    if(is[y])
		mx=max(mx,dp[y]);
	    else
		dp[u]+=dp[y];
	}
    }
    if(mx!=-1)
	dp[u]+=mx,is[u]=1;
}

void dfs2(int u,int par=-1){
    if(mark[u]==1){
	for(int y:v[u]){
	    if(y!=par){
		dp2[y]=0;is2[y]=1;
		dfs2(y,u);
	    }
	}
	return;
    }
    if(is2[u] && is[u]) ANS=max(ANS,max(dp2[u]+1,dp[u]));
    else ANS=max(ANS,dp[u]+dp2[u]);
    int mx1=0,mx2=0,cnt=0,sm=0;
    bool IS=0;
    for(int y:v[u]){
	IS|=(y!=par && mark[y]);
	if(y!=par && !mark[y]){
	    if(is[y]){
		cnt++;
		if(dp[mx1]<dp[y])
		    mx2=mx1,mx1=y;
		else if(dp[mx2]<dp[y])
		    mx2=y;
	    }
	    else{
		sm+=dp[y];
	    }
	}
    }
    for(int y:v[u]){
	if(y!=par){
	    if(mark[y]){
		is2[y]=1;dp2[y]=0;
	    }
	    else{
		is2[y]=IS|is2[u]|(cnt-is[y]);
		dp2[y]=sm-(is[y]?0:dp[y])+1+(is2[u]?0:dp2[u]);
		int MX=is2[u]?dp2[u]:0;
		if(y==mx1) MX=max(MX,dp[mx2]);
		else MX=max(MX,dp[mx1]);
		dp2[y]+=MX;
	    }
	    dfs2(y,u);
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    int l=1,r=1e6,ans=1;
    while(l<=r){
	int mid=(l+r)>>1;
	for(int i=1;i<=n;i++)
	    mark[i]=(a[i]<mid);
	dfs1(1);
	for(int i=1;i<=n;i++)
	    mark[i]=(a[i]<mid);
	memset(dp2,0,sizeof dp2);
	memset(is2,0,sizeof is2);
	ANS=0;
	dfs2(1);
	if(ANS>=k)
	    ans=mid,l=mid+1;
	else
	    r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}