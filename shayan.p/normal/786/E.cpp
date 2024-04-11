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

const int maxn=4e5+10,LG=15,inf=1e9,Sink=1,Source=2;

vector<pii> v[maxn],g[maxn],cut;
vector<int>idv[maxn],ans1,ans2;
int refind[maxn];
int sp[LG][maxn],id[LG][maxn],C=5;
int arr[maxn],h[maxn],pt[maxn];

void add_edge(int a,int b,int w){
    v[a].PB({b,w});
    v[b].PB({a,0});
    idv[a].PB(sz(v[b])-1);
    idv[b].PB(sz(v[a])-1);
}

void prep(int u,int par=0,int ID=-2,int H=1){
    h[u]=H;
    sp[0][u]=par;id[0][u]=++C;
    add_edge(C,Sink,1);
    refind[C]=ID;
    for(int i=1;i<LG;i++){
	sp[i][u]=sp[i-1][sp[i-1][u]];
	id[i][u]=++C;
	add_edge(C,id[i-1][u],inf);
	add_edge(C,id[i-1][sp[i-1][u]],inf);
    }
    for(pii p:g[u]){
	if(p.F!=par)
	    prep(p.F,u,p.S,H+1);
    }
}

void Add(int a,int b){
    add_edge(Source,++C,1);
    if(h[a]<h[b]) swap(a,b);
    for(int i=LG-1;i>=0;i--){
	if(h[sp[i][a]]>=h[b])
	    add_edge(C,id[i][a],inf),a=sp[i][a];
    }
    if(a==b) return;
    for(int i=LG-1;i>=0;i--){
	if(sp[i][a]!=sp[i][b])
	    add_edge(C,id[i][a],inf),add_edge(C,id[i][b],inf),a=sp[i][a],b=sp[i][b];
    }
    add_edge(C,id[0][a],inf);
    add_edge(C,id[0][b],inf);
}

bool bfs(int Source,int Sink){
    memset(h,0,sizeof h);
    int L=0,R=0;
    arr[R++]=Source;
    h[Source]=1;
    while(L<R){
	int u=arr[L++];
	if(u==Sink) return 1;
	for(pii p:v[u]){
	    if(p.S>0 && h[p.F]==0)
		h[p.F]=h[u]+1,arr[R++]=p.F;
	}
    }
    return 0;
}

int dfs(int u,int Sink,int flow){// flow > 0
    if(u==Sink) return flow;
    int ans=0;
    while(pt[u]<sz(v[u])){
	int &y=v[u][pt[u]].F,&w=v[u][pt[u]].S,&w2=v[y][idv[u][pt[u]]].S;
	if(h[u]+1==h[y] && w>0){
	    int num=dfs(y,Sink,min(flow,w));
	    ans+=num;w-=num;w2+=num;
	}
	if(flow==ans) break;
	++pt[u];
    }
    return ans;
}

int flow(int Source,int Sink){
    int ans=0;
    while(bfs(Source,Sink)){
	memset(pt,0,sizeof pt);
	ans+=dfs(Source,Sink,inf);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	g[a].PB({b,i});
	g[b].PB({a,i});
    }
    prep(1);
    int start=C+1;
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	Add(a,b);
    }

    cout<<flow(Source,Sink)<<"\n";

    for(int i=0;i<maxn;i++){
	for(pii p:v[i]){
	    if(h[i]>0 && h[p.F]==0 && p.S==0)
		cut.PB({i,p.F});
	}
    }
    for(pii p:cut){
	if(p.F==Source)
	    ans1.PB(p.S-start+1);
	if(p.S==Sink)
	    ans2.PB(refind[p.F]+1);
    }
    cout<<sz(ans1)<<" ";
    for(int x:ans1)
	cout<<x<<" ";
    cout<<"\n";
    cout<<sz(ans2)<<" ";
    for(int x:ans2)
	cout<<x<<" ";
    cout<<"\n";
    return 0;
}