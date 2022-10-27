#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 800000 + 10;
int n,m;
int deg[N], head[N], vis[N], edge_cnt=0;
struct Edge {
    int to, nex, fg;
} edge[N];
vector<int> ans;
vector< pair<int,int> > result; 

int vec[N], tot; 
void Euler(int x) {
    vec[++tot] = x;
    while(tot > 0) {
        int u = vec[tot];
        vis[u] = 1;
        if (head[u] == -1) {
            ans.push_back(u);
            tot --;
            continue;
        }
        if (edge[head[u]].fg == 1) {
            head[u] = edge[head[u]].nex;
            continue;
        }
        int v = edge[head[u]].to;
        edge[head[u]].fg = edge[head[u]^1].fg = 1;
        vec[++tot] = v;
        head[u] = edge[head[u]].nex; 
    }
}
void addEdge(int u,int v) {
    edge[edge_cnt].to = v;
    edge[edge_cnt].nex = head[u];
    edge[edge_cnt].fg = 0;
    head[u] = edge_cnt ++;
}
int main() {
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u, v; 
        scanf("%d%d",&u,&v);
        //u=1,v=i;
        addEdge(u, v); addEdge(v, u);
        deg[u] ++, deg[v] ++;
    }
    vector<int> odd;
    for(int i=1;i<=n;i++) {
        if(deg[i]&1) odd.push_back(i);
    }
    for(int i=0;i<(int)odd.size()-1;i+=2) {
        addEdge(odd[i], odd[i+1]);
        addEdge(odd[i+1], odd[i]);
    }

    for(int i=1;i<=n;i++) {
        if(vis[i]==0) {
            ans.clear();
            Euler(i);
            if (ans.size() == 0) continue;  
            /*
            printf("miao\n");
            for(int j=0;j<ans.size();j++)
                printf("%d ", ans[j]);
            printf("\n");
            */
            bool flag = 1;
            for(int j=0;j<(int)ans.size()-1;j++) {
                if(flag) result.push_back(make_pair(ans[j], ans[j+1]));
                else result.push_back(make_pair(ans[j+1], ans[j]));
                flag ^= 1;
            }
            if(flag == 0) result.push_back(make_pair(ans[0], ans[0]));
        }
    }
    printf("%d\n", result.size());
    for(int i=0;i<result.size();i++) {
        printf("%d %d\n", result[i].first, result[i].second);
    }
}