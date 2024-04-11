#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1022;
int n,m,vis[N],dis[N];

vector<int> g[N];

int bfs(int u){
    queue<int> q; q.push(u); vis[u]=1;
    vector<int> vec;
    while(q.size()){
        int u=q.front(); q.pop(); 
        vec.push_back(u);
        for(auto v:g[u]){
            if(vis[v]==1)continue;
            vis[v]=1; q.push(v); dis[v]=dis[u]+1;
        }
    }
    int bst=0,mx=0;
    for(auto x:vec) {
        if(dis[x]>=mx) {
            mx=dis[x]; bst=x;
        }
    }
    return bst;
}

pair<int,int> getD(int src) {
    bool v[N]={0}; int pre[N]={0},d[N]={0};
    vector<int> vec;
    queue<int> q; q.push(src); v[src]=1;
    while(q.size()){
        int u=q.front(); q.pop(); vec.push_back(u);
        //printf("d[%d]=%d\n", u,d[u]);
        for(auto x:g[u]){
            if(v[x]==1)continue;
            v[x]=1; q.push(x); d[x]=d[u]+1;
            pre[x]=u;
        }
    }
    int len=0,bst=0;
    for(auto i: vec){
        if(d[i]>=len) {
            len=d[i]; bst=i;
        }
    }
    int now=bst;
    while(d[now]>len/2) now=pre[now];
    return make_pair(len,now);
}

vector< pair<int,int> > vec;
pair<int,int> ans[N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0) {
            int rt = bfs(i);
            pair<int,int> p = getD(rt);
            vec.push_back(p);
        }
    }
    sort(vec.begin(),vec.end());
    int mx=vec[(int)vec.size()-1].first;

    if(vec.size()>=2) {
        for(int i=0;i<vec.size()-1;i++){
            for(int j=i+1;j<vec.size()-1;j++){
                mx=max(mx, (vec[i].first+1)/2 + (vec[j].first+1)/2 + 2);
            }
        }
        for(int i=0;i<vec.size()-1;i++){
            mx = max(mx,(vec[i].first+1)/2 + (vec[vec.size()-1].first+1)/2 + 1);
        }
    }
    printf("%d\n", mx);
    for(int i=0;i<(int)vec.size()-1;i++)
        printf("%d %d\n", vec[i].second,vec[(int)vec.size()-1].second);
}