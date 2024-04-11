#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100000+10;
int n,L,W;
int sz[N],mx[N],vis[N];
vector<int> miao;
vector< pair<int,int> > nod,g[N];
int bit[N],T[N],C;
void add(int pos,int x){
    while(pos<=n+1) {
        if(T[pos]!=C)T[pos]=C,bit[pos]=0;
        bit[pos]+=x; pos+=pos&-pos;
    }
}
int sum(int pos){
    int ans=0;
    while(pos>0){
        if(T[pos]!=C)T[pos]=C,bit[pos]=0;
        ans+=bit[pos]; pos-=pos&-pos;
    } return ans;
}
void dfs_miao(int u,int p){
    miao.push_back(u); 
    sz[u]=1,mx[u]=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first; if(v==p||vis[v])continue;
        dfs_miao(v,u); sz[u]+=sz[v]; mx[u]=max(mx[u],sz[v]);
    }
}
int getroot(int u){
    miao.clear(); dfs_miao(u,u);
    int mn=N,rt=0;
    for(auto x: miao) {
        mx[x]=max(mx[x],sz[u]-sz[x]);
        if(mx[x]<mn){
            mn=mx[x]; rt=x;
        }
    } return rt;
}
void dfs_init(int u,int p,int dep,int dis){
    nod.push_back(make_pair(dis,dep));
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first; if(v==p||vis[v])continue;
        dfs_init(v,u,dep+1,dis+g[u][i].second);
    }
}
LL ans=0;
void Excalibur(int u,int p,int dep,int dis,int sgn){
    nod.clear(); dfs_init(u,p,dep,dis); sort(nod.begin(),nod.end());
    LL tmp=0; ++C;
    for(int r=nod.size()-1,l=0;r>=0;r--){
        while(l<nod.size() && nod[l].first+nod[r].first<=W) {
            add(nod[l].second+1, 1); l++;
        }
        tmp += sum(L-nod[r].second+1);
    }
    for(auto p: nod){
        if(p.first*2<=W && p.second*2<=L) tmp--;
    } ans += tmp/2*sgn;
}

void solve(int u){
    //printf("u=%d\n", u);
    u=getroot(u);vis[u]=1; 
    Excalibur(u,u,0,0, +1);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first; if(vis[v])continue;
        Excalibur(v,u,1,g[u][i].second, -1);
        solve(v);
    }
}

int main(){
    scanf("%d%d%d",&n,&L,&W);
    for(int i=2;i<=n;i++){
        int p,w; scanf("%d%d",&p,&w);
        g[p].push_back(make_pair(i,w));
        g[i].push_back(make_pair(p,w));
    }
    solve(1);
    cout<<ans<<endl;
}