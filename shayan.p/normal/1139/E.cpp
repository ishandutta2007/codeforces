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

const int maxn=1e4+10,Max=5005,src=0,snk=maxn-1,inf=1e7;

pii p[maxn];
int pt[maxn],h[maxn];
vector<int>vid[maxn];
vector<pii>v[maxn];

void add_edge(int a,int b){
    vid[a].PB(sz(v[b]));
    vid[b].PB(sz(v[a]));
    v[a].PB({b,1});
    v[b].PB({a,0});
}
bool bfs(){
    queue<int>q;
    memset(h,-1,sizeof h);
    q.push(src),h[src]=0;
    while(sz(q)){
	int u=q.front();
	if(u==snk) return 1;
	q.pop();
	for(int i=0;i<sz(v[u]);i++){
	    pii p=v[u][i];
	    if(p.S==0 || h[p.F]!=-1) continue;
	    h[p.F]=h[u]+1;
	    q.push(p.F);
	}
    }
    return 0;
}
int dfs(int u,int flw=inf){
    if(u==snk) return flw;
    int ans=0;
    for(int &i=pt[u];i<sz(v[u]);i++){
	int y=v[u][i].F,&w=v[u][i].S,&w2=v[y][vid[u][i]].S;
	if(h[u]+1==h[y]){
	    int num=dfs(y,min(w,flw-ans));
	    ans+=num;
	    w-=num;
	    w2+=num;
	    if(ans==flw) break;
	}
    }
    return ans;
}

int FLW;

int flow(){
    while(bfs()){
	memset(pt,0,sizeof pt);
	FLW+=dfs(src);
    }
    return FLW;
}

bool is[maxn];
int tdo[maxn],Ans[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
	cin>>p[i].F;
	++p[i].F;
    }
    for(int i=1;i<=n;i++){
	cin>>p[i].S;
    }
    int d;cin>>d;
    for(int i=0;i<d;i++){
	cin>>tdo[i];
	is[tdo[i]]=1;
    }
    for(int i=1;i<=n;i++){
	if(!is[i])
	    add_edge(p[i].F,p[i].S+Max);
    }
    for(int i=1;i<=m;i++){
	add_edge(i+Max,snk);
    }
    int pos=1;
    add_edge(src,1);
    for(int i=d-1;i>=0;i--){
	while(flow()==pos){
	    add_edge(src,++pos);
	}
	Ans[i]=pos-1;
	add_edge(p[tdo[i]].F,p[tdo[i]].S+Max);
    }
    for(int i=0;i<d;i++){
	cout<<Ans[i]<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.