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

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
int val[maxn],sp[20][maxn],rt=1;
ll ans;

void dfs(int u,int par=0){
    sp[0][u]=par;
    for(int i=1;i<20;i++)
	sp[i][u]=sp[i-1][sp[i-1][u]];
    ll mn=inf;
    for(int i=0;i<20;i++){
	if(sp[i][u]!=0){
	    mn=min(mn,1ll*val[u]+1ll*val[sp[i][u]]*(i+1));
	}
	else{
	    if(u!=rt && sp[i-1][u]!=rt)
		mn=min(mn,1ll*val[u]+1ll*val[rt]*(i+1));
	}
    }
    if(mn!=inf)
	ans+=mn;
    for(int y:v[u]){
	if(y!=par)
	    dfs(y,u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>val[i];
	if(val[i]<val[rt])
	    rt=i;
    }
    for(int i=1;i<n;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(rt);
    cout<<ans<<endl;
    return 0;
}