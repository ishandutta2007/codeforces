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

const int maxn=5e5+10,LG=22;

int st[maxn],bg[maxn],sp[LG][2*maxn],h[maxn],SZ[maxn],C;
vector<int>v[maxn],g[maxn],lc;
vector<pii>vh[maxn];
ll ans[maxn];

void dfs1(int u,int H=1,int par=0){
    sp[0][u]=par;
    st[u]=++C;
    bg[u]=sz(lc);
    lc.PB(u);
    h[u]=H;
    vh[H].PB({st[u],u});
    for(int y:v[u])
	dfs1(y,H+1,u),lc.PB(u);
}

void dfs2(int u){
    for(int y:g[u])
	dfs2(y),SZ[u]+=SZ[y];
}

void dfs3(int u,ll num){
    if(SZ[u]==1) ans[u]+=num+h[u];
    for(int y:g[u])
	dfs3(y,num+1ll*h[u]*(SZ[u]-SZ[y]));
}

void dfs4(int u,int par=0){
    ans[u]+=ans[par];
    for(int y:v[u])
	dfs4(y,u);
}

inline int LCA(int a,int b){
    if(st[a]>st[b]) swap(a,b);
    int l=31-__builtin_clz(bg[b]-bg[a]+1);
    int A=sp[l][bg[a]],B=sp[l][bg[b]-(1<<l)+1];
    if(h[A]<h[B])return A;
    return B;
}

int main(){
    int n,r=1;scanf("%d",&n);
    for(int i=1;i<=n;i++){
	int x;scanf("%d",&x);
	if(x==0) r=i;
	else v[x].PB(i);
    }
    dfs1(r);
    for(int i=0;i<sz(lc);i++)
	sp[0][i]=lc[i];
    for(int i=1;i<LG;i++){
	for(int j=0;j<sz(lc);j++){
	    int A=sp[i-1][j],B=(1<<(i-1))+j>=sz(lc)?0:sp[i-1][(1<<(i-1))+j];
	    sp[i][j]=(h[A]<h[B]?A:B);
	}
    }
    for(int i=1;i<maxn;i++){
	if(vh[i].empty())continue;
	for(int j=sz(vh[i])-1;j>0;j--){
	    int u=LCA(vh[i][j].S,vh[i][j-1].S);
	    vh[i].PB({st[u],u});
	}
	sort(vh[i].begin(),vh[i].end());
	vh[i].resize(unique(vh[i].begin(),vh[i].end())-vh[i].begin());
	for(int j=0;j<sz(vh[i]);j++)
	    g[vh[i][j].S].clear(),SZ[vh[i][j].S]=(h[vh[i][j].S]==i);
	for(int j=1;j<sz(vh[i]);j++)
	    g[LCA(vh[i][j].S,vh[i][j-1].S)].PB(vh[i][j].S);
	dfs2(vh[i][0].S);
	dfs3(vh[i][0].S,0);
    }
    dfs4(r);
    for(int i=1;i<=n;i++)
	printf("%lld ",ans[i]-h[i]);
    printf("\n");
    return 0;
}