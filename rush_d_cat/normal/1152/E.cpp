#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
const int N=200000+10;
int n; pair<int,int> p[N];
int head[N],edge_cnt, deg[N],vec[N],tot;
struct Edge {
    int to, w, nex, fg;
} edge[N<<2];
void init() {
    memset(head,-1,sizeof(head));
}
void addEdge(int u,int v,int w) {
    edge[edge_cnt].to = v;
    edge[edge_cnt].nex = head[u];
    edge[edge_cnt].w = w;
    head[u] = edge_cnt ++; 
}
stack<int> ans;
void solve(int u) {
    vec[++tot] = u;
    while(tot) {
        int u = vec[tot];
        if (head[u] == -1) {
            tot --;
            ans.push(u);
            continue;
        }
        int v = edge[head[u]].to;
        if (edge[head[u]].fg) {
            head[u] = edge[head[u]].nex;
            continue;
        }
        edge[head[u]].fg = edge[head[u]^1].fg = 1;
        vec[++tot] = v;
    }
}
vector<int> v;
int id(int x){
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++) scanf("%d",&p[i].first), v.push_back(p[i].first);
    for(int i=1;i<n;i++) {
        scanf("%d",&p[i].second), v.push_back(p[i].second);
        if(p[i].second < p[i].first) return !printf("-1\n");
    }
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<n;i++) p[i].first=id(p[i].first), p[i].second=id(p[i].second);
    init();
    for(int i=1;i<n;i++){ 
        deg[p[i].first] ++, deg[p[i].second] ++;
        addEdge(p[i].first,p[i].second,1); 
        addEdge(p[i].second,p[i].first,1);
    }
    vector<int> one;
    for(int i=1;i<=n;i++){
        if(deg[i]&1) one.push_back(i);
    }

    if(one.size()>2) return !printf("-1\n");
    else if(one.size()==2) solve(one[0]);
    else solve(1);

    vector<int> path;
    while(ans.size()) {
        path.push_back(ans.top()); ans.pop();
    }
    if(path.size()!=n) return !printf("-1\n");
    for(int i=0;i<path.size();i++) {
        printf("%d ", v[path[i]-1]);
    }
}