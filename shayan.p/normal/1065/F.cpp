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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

int n,k,sp[20][maxn],sc[maxn],scr[maxn],type[maxn],dp[maxn],C,SC;
vector<int>g[maxn],v[maxn],vv[maxn],st;
bool mark[maxn];

void dfs(int u,int par=0){
    sp[0][u]=par;
    for(int i=1;i<20;i++)
	sp[i][u]=sp[i-1][sp[i-1][u]];
    for(int y:g[u]){
	if(y!=par)
	    dfs(y,u);
    }
    if(par!=0){
	vv[u].PB(par);
    }
    if(par!=0 && sz(g[u])==1){
	sc[u]=1;
	int lim=k,y=u;
	for(int i=19;i>=0;i--){
	    if(sp[i][y]!=0 && lim>=(1<<i))
		y=sp[i][y],lim-=(1<<i);
	}
	vv[y].PB(u);
    }
    st.PB(u);
}

void dfs2(int u){
    mark[u]=1;
    type[u]=C;
    SC+=sc[u];
    for(int y:vv[u]){
	if(!mark[y])
	    dfs2(y);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    for(int i=2;i<=n;i++){
	int x;cin>>x;
	g[x].PB(i);
	g[i].PB(x);
    }
    dfs(1);
    for(int i=sz(st)-1;i>=0;i--){
	if(!mark[st[i]])
	    ++C,SC=0,dfs2(st[i]),scr[C]=SC;
    }
    for(int i=1;i<=n;i++){
	for(int j:g[i])
	    if(type[i]!=type[j])
		v[type[j]].PB(type[i]);
    }
    int ans=scr[1];
    dp[1]=scr[1];
    for(int i=2;i<=C;i++){
	for(int j:v[i])
	    dp[i]=max(dp[i],dp[j]);
	dp[i]+=scr[i];
	ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}