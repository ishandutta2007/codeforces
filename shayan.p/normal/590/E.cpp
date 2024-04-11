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
typedef long double ld;

const int maxn=750*2+10,Max=1e7+10,src=maxn-2,snk=maxn-1,inf=1e9;

struct Flow{
    vector<pii>v[maxn];
    vector<int>vid[maxn];
    int h[maxn],pt[maxn];
    
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
	    for(pii p:v[u]){
		if(p.S>0 && h[p.F]==-1){
		    h[p.F]=h[u]+1;
		    q.push(p.F);
		}
	    }
	}
	return 0;
    }
    int dfs(int u,int flw=inf){
	if(u==snk) return flw;
	int ans=0;
	for(int &i=pt[u];i<sz(v[u]);i++){
	    int y=v[u][i].F,&w=v[u][i].S,&w2=v[y][vid[u][i]].S;
	    if(h[u]+1==h[y] && w>0){
		int num=dfs(y,min(w,flw-ans));
		ans+=num;
		w-=num,w2+=num;
	    }
	    if(ans==flw) break;
	}
	return ans;
    }
    int flow(){
	int ans=0;
	while(bfs()){
	    memset(pt,0,sizeof pt);
	    ans+=dfs(src);
	}
	return ans;
    }
}; Flow flw;

struct Aho{
    int who[Max],up[Max],nxt[Max][2],f[Max],C;
    Aho(){
	memset(who,-1,sizeof who);
	memset(nxt,0,sizeof nxt);
	memset(f,0,sizeof f);
	memset(up,0,sizeof up);
	C=0;
    }
    void add(string &s,int id){
	int tmp=0;
	for(int i=0;i<sz(s);i++){
	    if(nxt[tmp][s[i]-'a']==0) nxt[tmp][s[i]-'a']=++C;
	    tmp=nxt[tmp][s[i]-'a'];
	}
	who[tmp]=id;
    }
    void build(){
	queue<int>q;
	for(int i=0;i<2;i++){
	    if(nxt[0][i]>0) q.push(nxt[0][i]);
	}
	while(sz(q)){
	    int u=q.front();
	    q.pop();
	    up[u]= who[f[u]]==-1 ? up[f[u]] : f[u];
	    for(int i=0;i<2;i++){
		if(nxt[u][i]>0) f[nxt[u][i]]=nxt[f[u]][i],q.push(nxt[u][i]);
		else nxt[u][i]=nxt[f[u]][i];
	    }
	}
    }
}; Aho aho;

string s[maxn];
bool mark[Max];
vector<int>vec;
int f[maxn],rf[maxn],n;
bool adj[maxn][maxn];
vector< vector<int> >pth;

void go(int u){
    for(pii p:flw.v[u]){
	if(p.S==0){
	    if(u<n && p.F!=src) rf[p.F-n]=u,f[u]=p.F-n;
	    if(p.F<n) go(p.F);
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>s[i];
	aho.add(s[i],i);
    }
    aho.build();
    for(int i=0;i<n;i++){
	int tmp=0;
	for(int j=0;j<sz(s[i]);j++){
	    tmp=aho.nxt[tmp][s[i][j]-'a'];
	    int tmp2=(aho.who[tmp]==-1 ? aho.up[tmp] : tmp);
	    while(tmp2>0 && mark[tmp2]==0){
		mark[tmp2]=1;
		vec.PB(tmp2);
		tmp2=aho.up[tmp2];
	    }
	}

	for(int x:vec){
	    if(aho.who[x]!=i) flw.add_edge(aho.who[x],n+i) , adj[aho.who[x]][i]=1;
	    mark[x]=0;
	}
	vec.clear();
    }
    
    for(int i=0;i<n;i++){
	flw.add_edge(src,i);
	flw.add_edge(n+i,snk);
    }
    flw.flow();
    memset(f,-1,sizeof f);
    memset(rf,-1,sizeof rf);
    go(src);
    for(int i=0;i<n;i++){
	if(f[i]==-1){
	    int tmp=i;
	    vec.clear();
	    while(tmp!=-1){
		vec.PB(tmp);
		tmp=rf[tmp];
	    }
	    pth.PB(vec);
	}
    }

    while(true){
	for(vector<int>&v1:pth){
	    for(vector<int>&v2:pth){
		if(adj[v1.back()][v2.back()]){
		    v1.pop_back();
		    goto Hell;
		}
	    }
	}
	break;
    Hell:;
    }
    cout<<sz(pth)<<"\n";
    for(vector<int>&v:pth){
	cout<<v.back()+1<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.