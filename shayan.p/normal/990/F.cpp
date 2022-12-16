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

int a[maxn],A[maxn],B[maxn],vl[maxn],ans[maxn];
vector<pii>pos,neg,v[maxn];
int mark[maxn];

void dfs(int u){
    mark[u]=1;
    if(a[u]<0) neg.PB({-a[u],u});
    if(a[u]>0) pos.PB({a[u],u});
    for(pii p:v[u]){
	if(!mark[p.F])
	    dfs(p.F);
    }
}

int dfs2(int u){
    mark[u]=2;
    int num=vl[u];
    for(pii p:v[u]){
	if(mark[p.F]!=2){
	    int num2=dfs2(p.F);
	    if(A[p.S]==u) ans[p.S]=num2;
	    else          ans[p.S]=-num2;
	    num+=num2;
	}
    }
    return num;
}

void solve(int u){
    pos.clear(),neg.clear();
    dfs(u);
    int sm=0;
    for(pii p:pos)
	sm+=p.F;
    for(pii p:neg)
	sm-=p.F;
    if(sm!=0) cout<<"Impossible\n",exit(0);
    while(sz(pos) || sz(neg)){
	int mn=min(neg.back().F,pos.back().F);
	vl[neg.back().S]-=mn,vl[pos.back().S]+=mn;
	neg[sz(neg)-1].F-=mn,pos[sz(pos)-1].F-=mn;
	while(neg.back().F==0) neg.pop_back();
	while(pos.back().F==0) pos.pop_back();
    }
    dfs2(u);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
	cin>>A[i]>>B[i];
	v[A[i]].PB({B[i],i});
	v[B[i]].PB({A[i],i});
    }
    for(int i=1;i<=n;i++){
	if(!mark[i])
	    solve(i);
    }
    cout<<"Possible\n";
    for(int i=0;i<m;i++){
	cout<<ans[i]<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.