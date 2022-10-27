#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
const int N = 300000+10;
int n, m;
vector<int> g[N], bcc[N];
map< pair<int,int>, int > bridge;
struct BCC {
    int pre[N], low[N], iscut[N], bccno[N];
    int dfs_clock, bcc_cnt;
    stack< pair<int,int> > S;
    
    int dfs(int u, int p) 
    {
        int lowu = pre[u] = ++ dfs_clock;
        int child = 0;
        for (int i = 0; i < g[u].size(); i ++) 
        {
            int v = g[u][i];
            pair<int, int> edge = make_pair(u, v);
            if (! pre[v])
            {   
                S.push(edge);
                child ++;
                int lowv = dfs(v, u);
                lowu = min(lowu, lowv);
                if (lowv > pre[u]) { 
                    //printf("%d -> %d\n", u,v);
                    bridge[make_pair(u,v)] = bridge[make_pair(v, u)] = 1;
                    bcc[++ bcc_cnt].clear();
                    iscut[u] = 1;
                    for (;;) {
                        pair<int, int> x = S.top(); S.pop();
                        if (bccno[x.first] != bcc_cnt) {
                            bccno[x.first] = bcc_cnt;
                            bcc[bcc_cnt].push_back(x.first);
                        }
                        if (bccno[x.second] != bcc_cnt) {
                            bccno[x.second] = bcc_cnt;
                            bcc[bcc_cnt].push_back(x.second);
                        }
                        if (x.first == u && x.second == v)
                            break;
                    }
                } 
            } else 
            if (pre[v] < pre[u] && v != p) {
                S.push(edge);
                lowu = min(lowu, pre[v]);
            }
        }
        if (p == -1 && child <= 1) iscut[u] = 0;
        return lowu;
    }

    int color[N], cur=1, flag[N];
    void dfs2(int u) {
        color[u]=cur;
        for(int i=0;i<g[u].size();i++) {
            int v=g[u][i];
            if(bridge[make_pair(u,v)]) continue;
            if(color[v]) continue;
            dfs2(v);
        }
    }
    vector<int> gragh[N];
    void dfs3(int u) {
        flag[u]=1;
        for(int i=0;i<g[u].size();i++) {
            int v=g[u][i];
            if(flag[v]) continue;
            if(color[u] != color[v]) {
                gragh[color[u]].push_back(color[v]);
                gragh[color[v]].push_back(color[u]);
            }
            dfs3(v);
        }
    }

    int far=-1,max_dis=-1;
    void bfs(int s) {
        int dis[N];
        memset(dis,-1,sizeof(dis));
        queue<int> q;
        q.push(s); dis[s]=0;
        while(q.size()) {
            int u=q.front(); q.pop();
            for(int i=0;i<gragh[u].size();i++) {
                int v=gragh[u][i];
                if(dis[v]!=-1) continue;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
        far=-1,max_dis=-1;
        for(int i=1;i<N;i++) {
            if(dis[i]!=-1) {
                if(dis[i]>max_dis) {
                    max_dis = dis[i];
                    far = i;
                }
            }
        }
    }

    void Excalibur(int n) 
    {
        memset(pre, 0, sizeof(pre));
        memset(low, 0, sizeof(low));
        memset(iscut, 0, sizeof(iscut));
        memset(bccno, 0, sizeof(bccno));
        dfs_clock = bcc_cnt = 0;
        //printf("ok\n");
        for (int i = 1; i <= n; i ++) {
            if (pre[i] == 0)
                dfs(i, -1);
        } 
        //printf("A\n");
        for(int i=1;i<=n;i++)
            if(color[i]==0) {
                dfs2(i); cur ++;
            }
        //printf("B\n");
        memset(flag,0,sizeof(flag));
        dfs3(1);
       // printf("C\n");
        bfs(1);
        bfs(far);
        //printf("D\n");
        printf("%d\n", max_dis);
        /*
        for(int i=1;i<=n;i++){
            for(int j=0;j<g[i].size();i++) {
                if(bridge[make_pair(i,g[i][j])]) {
                    printf("! %d %d\n", i, g[i][j]);
                }
            }
        }  
        */
    }
} Saber;


int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Saber.Excalibur(n);
}