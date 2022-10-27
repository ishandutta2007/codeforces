#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int N=200000+10;
int n,m,k,u[N],v[N],deg[N],vis[N],ans[N],rem;
set<int> g[N];
queue<int> q;
void update() {
    while(q.size()) {
        int u=q.front();q.pop();
        //printf("u = %d\n", u);
        for(auto v: g[u]) { 
            g[v].erase(u); deg[u]--, deg[v]--;
            if(deg[v]<k&&vis[v]==0) {q.push(v); vis[v]=1; rem--;}
        }
    }
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&u[i],&v[i]);
        g[u[i]].insert(v[i]);deg[u[i]]++;
        g[v[i]].insert(u[i]);deg[v[i]]++;
    }
    rem=n;
    for(int i=1;i<=n;i++) {
        if(deg[i]<k) {
            q.push(i); vis[i]=1; rem --;
        }
    }
    update();ans[m]=rem; //printf("ans=%d\n", rem);
    for(int i=m;i>=1;i--) {
        if(vis[u[i]]==0 && vis[v[i]]==0) {
            deg[u[i]]--,deg[v[i]]--; 
            g[u[i]].erase(v[i]); g[v[i]].erase(u[i]);
            
            if(deg[u[i]]==k-1 && vis[u[i]]==0) {q.push(u[i]); vis[u[i]]=1; rem --;} 
            if(deg[v[i]]==k-1 && vis[v[i]]==0) {q.push(v[i]); vis[v[i]]=1; rem --;}
        }
        update(); ans[i-1]=rem;
    }
    for(int i=1;i<=m;i++) printf("%d\n", ans[i]);
}