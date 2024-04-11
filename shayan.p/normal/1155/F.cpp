// Faster!

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

const int maxn=15,MASK=(1<<14)+10;

bool path[maxn][maxn][MASK],adj[maxn][maxn];
int dp[MASK],n;
pair<int,pii> bef[MASK];
vector<pii>ans;

void Add(int msk,int a,int b){
    if(__builtin_popcount(msk)==1){
	int x=__builtin_ctz(msk);
	ans.PB({x,a});
	ans.PB({x,b});
	return;
    }
    for(int k=0;k<n;k++){
	if(bit(msk,k) && adj[k][b] && path[a][k][msk ^ (1<<k)]){
	    ans.PB({k,b});
	    Add(msk ^ (1<<k),a,k);
	    return;
	}
    }
    assert(0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int m;cin>>n>>m;
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	--a,--b;
	adj[a][b]=adj[b][a]=1;
    }
    for(int msk=1;msk<(1<<n);msk++){
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
		if(__builtin_popcount(msk)==1){
		    int x=__builtin_ctz(msk);
		    path[i][j][msk]=(i!=j && adj[x][i] && adj[x][j]);
		    continue;
		}
		if(bit(msk,i) || bit(msk,j)) continue;
		for(int k=0;k<n;k++){
		    path[i][j][msk] |= bit(msk,k) && adj[k][j] && path[i][k][msk ^ (1<<k)];
		}
	    }
	}
    }
    for(int msk=1;msk<(1<<n);msk++){
	if(__builtin_popcount(msk)==1) continue;
	dp[msk]=m+10;
	for(int msk2=(msk-1) & msk ; msk2!=0 ; msk2=(msk2-1) & msk){
	    int msk3=msk ^ msk2;
	    for(int i=0;i<n;i++){
		if(bit(msk3,i)==0) continue;
		for(int j=0;j<n;j++){
		    if(bit(msk3,j)==0) continue;
		    int num=__builtin_popcount(msk2);
		    if(path[i][j][msk2] && dp[msk]>dp[msk3]+num+1) bef[msk]={msk2,{i,j}},dp[msk]=dp[msk3]+num+1;
		}
	    }
	}
    }
    int msk=(1<<n)-1;
    while(__builtin_popcount(msk)>1){
	Add(bef[msk].F,bef[msk].S.F,bef[msk].S.S);
	msk^=bef[msk].F;
    }
    assert(dp[(1<<n)-1]==sz(ans));
    cout<<sz(ans)<<"\n";
    for(pii p:ans){
	cout<<p.F+1<<" "<<p.S+1<<"\n";
    }
    return 0;;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.