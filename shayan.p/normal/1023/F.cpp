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

const int maxn=5e5+10,inf=2e9;

vector< pair<int,bool> >v[maxn];
bool Real[maxn];
int col[maxn],sp[21][maxn],h[maxn],w[maxn];
pii pr[maxn];
pair<int,pii> ed[maxn];

int pr2[maxn];

void dfs(int u,int H=1,int par=0){
    sp[0][u]=par;
    h[u]=H;
    pr[u]={-1,u};
    for(auto p:v[u]){
	if(p.F!=par)
	    dfs(p.F,H+1,u);
	else
	    Real[u]=p.S;
    }
}

int LCA(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    for(int i=19;i>=0;i--){
	if(h[sp[i][a]]>=h[b])
	    a=sp[i][a];
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
	if(sp[i][a]!=sp[i][b]){
	    a=sp[i][a];
	    b=sp[i][b];
	}
    }
    return sp[0][a];
}

pii Find(int u){
    if(pr[u].F<0) return {u,pr[u].S};
    return (pr[u]=Find(pr[u].F));
}

void Merge(int a,int b){
    if((a=Find(a).F)==(b=Find(b).F))return;
    if(pr[a].F>pr[b].F) swap(a,b);
    if(h[pr[a].S]>h[pr[b].S]) pr[a].S=pr[b].S;
    pr[a].F+=pr[b].F;
    pr[b].F=a;
}

int Find2(int u){
    if(pr2[u]<0) return u;
    return (pr2[u]=Find2(pr2[u]));
}

void Merge2(int a,int b){
    if((a=Find2(a))==(b=Find2(b)))return;
    if(pr2[a]>pr2[b]) swap(a,b);
    pr2[a]+=pr2[b];
    pr2[b]=a;
}

void Add(int a,int b,int c){// a paiin tare  // c vazn
    a=Find(a).S;
    while(h[a]>h[b]){
	w[a]=c;
	Merge(a,sp[0][a]);
	a=Find(a).S;
    }
}

int main(){
    fill(pr2,pr2+maxn,-1);
    int n,k,m;scanf("%d%d%d",&n,&k,&m);
    for(int i=0;i<k;i++){
	int a,b;scanf("%d%d",&a,&b);
	v[a].PB({b,1});v[b].PB({a,1});
	Merge2(a,b);
    }
    for(int i=0;i<m;i++){
	scanf("%d%d%d",&ed[i].S.F,&ed[i].S.S,&ed[i].F);
	if(Find2(ed[i].S.F)!=Find2(ed[i].S.S)){
	    ed[i].F=-1;
	    v[ed[i].S.F].PB({ed[i].S.S,0});
	    v[ed[i].S.S].PB({ed[i].S.F,0});
	    Merge2(ed[i].S.F,ed[i].S.S);
	}
    }
    dfs(1);
    for(int i=1;i<20;i++){
	for(int j=1;j<=n;j++)
	    sp[i][j]=sp[i-1][sp[i-1][j]];
    }
    fill(w,w+maxn,inf);
    for(int i=0;i<m;i++){
	if(ed[i].F==-1)continue;
	int p=LCA(ed[i].S.F,ed[i].S.S);
	Add(ed[i].S.F,p,ed[i].F);
	Add(ed[i].S.S,p,ed[i].F);
    }
    ll ans=0;
    for(int i=2;i<=n;i++){
	if(Real[i]){
	    if(w[i]==inf){
		printf("-1\n");
		return 0;
	    }
	    ans+=w[i];
	}
    }
    printf("%lld\n",ans);
    return 0;
}