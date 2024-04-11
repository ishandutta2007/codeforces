// Wanna Hack? GL...

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

ll dp[2][maxn],c[maxn];
set<int>opt[maxn];
vector<int>v[maxn],ans;

void dfs(int u,int par=-1){
    if(sz(v[u])==1 && par!=-1) {dp[0][u]=inf,dp[1][u]=0;return;}
    for(int y:v[u]){
	if(y!=par){
	    dfs(y,u);
	    dp[0][u]+=min(dp[1][y]+c[y],dp[0][y]);
	}
    }
    ll mn=dp[0][u];
    for(int y:v[u]){
	if(y!=par){
	    ll num=dp[0][u]-min(dp[0][y],dp[1][y]+c[y])+dp[1][y];
	    if(opt[u].empty() || mn>num) dp[1][u]=num,mn=num,opt[u].clear();
	    if(num==mn) opt[u].insert(y);
	}
    }
}
void dfs2(int u,ll lim1,ll lim2,int par=-1){
    //    cout<<u<<" "<<lim1<<" "<<lim2<<"    ";
    lim2=max(lim2,lim1-c[u]);
    //    cout<<lim2<<endl;
    if(sz(v[u])==1 && par!=-1){
	if(c[u]<=lim1) ans.PB(u);
	return;
    }
    if(dp[1][u]+c[u]<=lim1) ans.PB(u);
    for(int y:v[u]){
	if(y!=par){
	    ll num=dp[0][u]-min(dp[0][y],dp[1][y]+c[y]);
	    int pos1=*opt[u].begin(),pos2=*opt[u].rbegin(),id=-1;
	    if(pos1!=y) id=pos1;
	    if(pos2!=y) id=pos2;
	    dfs2(y,max(lim1-num,(id==-1?0:lim2-num+min(dp[0][id],dp[1][id]+c[id])-dp[1][id])),lim2-num,u);
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>c[i];
    }
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    dfs2(1,min(dp[1][1]+c[1],dp[0][1]),0);
    cout<<min(dp[1][1]+c[1],dp[0][1])<<" "<<sz(ans)<<"\n";
    sort(ans.begin(),ans.end());
    for(int x:ans){
	cout<<x<<" ";
    }
    return cout<<"\n",0;
}