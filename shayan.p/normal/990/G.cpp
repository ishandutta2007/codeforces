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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

ll ans[maxn];
int a[maxn],mark[maxn],C,comp;
vector<int>v[maxn],dv[maxn],tree[maxn];

void dfs(int u){
    mark[u]=C,comp++;
    for(int y:v[u]){
	if(mark[y]==C-1)
	    dfs(y);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=1;i<maxn;i++){
	for(int j=i;j<maxn;j+=i)
	    dv[j].PB(i);
    }
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>a[i];
	for(int x:dv[a[i]])
	    tree[x].PB(i);
    }
    for(int i=1;i<=n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b),v[b].PB(a);
    }
    for(int i=1;i<maxn;i++){
	++C;
	for(int u:tree[i]){
	    mark[u]=C;
	}
	++C;
	for(int u:tree[i]){
	    if(mark[u]==C) continue;
	    comp=0,dfs(u);
	    ans[i]+=(1ll*comp*(comp+1))/2;
	}
    }
    for(int i=maxn-1;i>=1;i--){
	for(int j=2*i;j<maxn;j+=i)
	    ans[i]-=ans[j];
    }
    for(int i=1;i<maxn;i++){
	if(ans[i]!=0)
	    cout<<i<<" "<<ans[i]<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.