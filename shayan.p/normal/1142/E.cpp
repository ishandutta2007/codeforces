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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn],rv[maxn],vv[maxn],scc[maxn],que,stk;
int id[maxn],deg[maxn],C,Ans,n,m;
bool mark[maxn];

void dfs(int u,bool task){
    if(task) id[u]=C,scc[C].PB(u);
    mark[u]=1;
    for(int y: (task ? rv[u] : v[u]) ){
	if(!mark[y])
	    dfs(y,task);
    }
    if(!task) stk.PB(u);
}
void del(int _id,int pos){
    int u=que[_id];
    for(int y:v[scc[u][pos]]){
	if(--deg[id[y]]==0)
	    que.PB(id[y]);
    }
    swap(scc[u][pos],scc[u][sz(scc[u])-1]);
    scc[u].pop_back();
    if(scc[u].empty()){
	swap(que[_id],que[sz(que)-1]);
	que.pop_back();
    }
}
bool Ask(int a,int b){
    cout<<"? "<<a+1<<" "<<b+1<<endl;
    bool ans;cin>>ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	v[--a].PB(--b);
	rv[b].PB(a);
    }
    for(int i=0;i<n;i++){
	if(!mark[i]) dfs(i,0);
    }
    memset(mark,0,sizeof mark);
    for(int i=sz(stk)-1;i>=0;i--){
	if(!mark[stk[i]]) dfs(stk[i],1),++C;
    }
    for(int u=0;u<n;u++){
	for(int y:v[u]){
	    if(id[u]==id[y]) continue;
	    vv[id[u]].PB(id[y]),deg[id[y]]++;
	}
    }
    for(int i=0;i<C;i++){
	if(deg[i]==0) que.PB(i);
    }
    Ans=scc[que[0]][0];
    while(sz(que)>1){
	if(Ask(Ans,scc[que[1]][0])) del(1,0);
	else swap(que[0],que[1]),Ans=scc[que[0]][0],del(1,0);
    }
    return cout<<"! "<<Ans+1<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.