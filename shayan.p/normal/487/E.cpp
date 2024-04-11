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

const int maxn=2e5+10,inf=2e9;

struct Tree{
    vector<int>v[maxn];
    int SZ[maxn],h[maxn],st[maxn],up[maxn],C;
    int val[2*maxn];

    Tree(){
	memset(SZ,0,sizeof SZ);
	memset(h,0,sizeof h);
	memset(st,0,sizeof st);
	memset(up,0,sizeof up);
	memset(val,0,sizeof val);
	C=0;
    }
    inline int Par(int u){
	return v[u].back();
    }
    void Edge(int a,int b){
	v[a].PB(b);
	v[b].PB(a);
    }
    void dfsz(int u,int par=-1){
	SZ[u]=1;
	for(int y:v[u]){
	    if(y!=par)
		dfsz(y,u),SZ[u]+=SZ[y];
	}
    }
    void dfs(int u,int H=1,bool is=0){
     	st[u]=++C;
	h[u]=H;
	up[u]=(is?up[Par(u)]:u);
	if(sz(v[u])>1)
	    dfs(v[u][sz(v[u])-2],H+1,1);
	for(int i=0;i<sz(v[u])-2;i++)
	    dfs(v[u][i],H+1,0);
    }
    void build(){
	for(int i=1;i<maxn;i++){
	    if(SZ[i]==0)
		dfsz(i);
	}
	for(int i=1;i<maxn;i++){
	    for(int j=0;j<sz(v[i]);j++)
		if(SZ[v[i][j]]>SZ[v[i][sz(v[i])-1]])
		    swap(v[i][j],v[i][sz(v[i])-1]);
	    for(int j=0;j<sz(v[i])-1;j++)
		if(SZ[v[i][j]]>SZ[v[i][sz(v[i])-2]])
		    swap(v[i][j],v[i][sz(v[i])-2]);
	}
	for(int i=1;i<maxn;i++){
	    if(st[i]==0)
		v[i].PB(-1),dfs(i);
	}
    }
    int Ask(int a,int b){
	int ans=inf;
	while(up[a]!=up[b]){
	    if(h[up[a]]<h[up[b]]) swap(a,b);
	    ans=min(ans,Askmn(st[up[a]],st[a]+1));
	    a=Par(up[a]);
	}
	if(h[a]>h[b]) swap(a,b);
	return min(ans,Askmn(st[a],st[b]+1));
    }
    int LCA(int a,int b){
 	while(up[a]!=up[b]){
	    if(h[up[a]]<h[up[b]]) swap(a,b);
	    a=Par(up[a]);
	}
	if(h[a]>h[b]) swap(a,b);
	return a;
    }
    int Askmn(int f,int s){// [)
	int ans=val[f+maxn];
	for(f+=maxn,s+=maxn;f<s;f>>=1,s>>=1){
	    if(f&1) ans=min(ans,val[f++]);
	    if(s&1) ans=min(ans,val[--s]);
	}
	return ans;
    }
    void Change(int u,int x){
	val[u=st[u]+maxn]=x;
	for(u>>=1;u>0;u>>=1)
	    val[u]=min(val[2*u],val[2*u+1]);
    }
};Tree tree;


int w[maxn],upd[maxn],h[maxn],n,C=1;
map<int,int>mp[maxn];
vector<int>v[maxn];

stack<int>stk;

int bcc(int u,int H=1,int par=-1){
    h[u]=H;
    int ans=H;
    stk.push(u);
    for(int y:v[u]){
	if(h[y]) ans=min(ans,h[y]);
	else ans=min(ans,bcc(y,H+1,u));
    }
    if(ans==H-1){
	while(stk.top()!=u){
	    tree.Edge(u+n+1,stk.top());
	    upd[stk.top()]=u+n+1;
	    stk.pop();
	}
	tree.Edge(u+n+1,u);
	tree.Edge(u+n+1,par);
	upd[u]=u+n+1;
	upd[par]=u+n+1;
	stk.pop();
    }
    if(par==-1){
	// size of stack should be 1
	stk.pop();
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int m,q;cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
	cin>>w[i];
	mp[i][w[i]]++;
    }
    while(m--){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    for(int i=1;i<=n;i++){
	if(h[i]==0)
	    bcc(i);
    }
    tree.build();
    for(int i=1;i<=n;i++){
	mp[upd[i]][w[i]]++;
    }
    for(int i=1;i<maxn;i++){
	if(!mp[i].empty())
	    tree.Change(i,mp[i].begin()->F);
    }
    while(q--){
	char task;cin>>task;
	int a,b;cin>>a>>b;
	if(task=='C'){
	    if(--mp[a][w[a]]==0) mp[a].erase(w[a]);
	    if(--mp[upd[a]][w[a]]==0) mp[upd[a]].erase(w[a]);
	    mp[a][w[a]=b]++;
	    mp[upd[a]][b]++;
	    tree.Change(a,mp[a].begin()->F);
	    tree.Change(upd[a],mp[upd[a]].begin()->F);
	}
	else{
	    int lc=tree.LCA(a,b);
     	    int ans=tree.Ask(a,b);
	    if(upd[lc]==0 && tree.Par(lc)!=-1)
		ans=min(ans,mp[tree.Par(lc)].begin()->F);
	    cout<<ans<<"\n";
	}
    }
}