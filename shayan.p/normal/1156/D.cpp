// High above the clouds there is a rainbow...

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

vector<int>v[2][maxn];
int com[2][maxn];
int C,SZ[maxn],mark[maxn];

void dfs(int u,int z){
    com[z][u]=C,SZ[C]++;
    mark[u]=1;
    for(int y:v[z][u]){
	if(!mark[y]) dfs(y,z);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b,c; cin>>a>>b>>c;
	v[c][a].PB(b);
	v[c][b].PB(a);
    }
    ll ans=0;
    for(int w=0;w<2;w++){
	memset(mark,0,sizeof mark);
	for(int i=1;i<=n;i++){
	    if(mark[i]==0) ++C,dfs(i,w),ans+=(1ll*SZ[C]*(SZ[C]-1));
	}
    }
    for(int i=1;i<=n;i++){
	ans+=1ll*(SZ[com[0][i]]-1)*(SZ[com[1][i]]-1);
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.