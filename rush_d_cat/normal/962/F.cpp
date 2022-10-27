#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 200000+10;
int n, m, u, v, cas;
vector<int> g[N], bcc[N];
map< pair<int, int>, int > id;
struct BCC {
    int pre[N], low[N], iscut[N], bccno[N];
    int dfs_clock, bcc_cnt;
    stack< pair<int,int> > S;
    
    vector<int> E[N];

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
                if (lowv >= pre[u]) { 
                    bcc[++ bcc_cnt].clear();
                    iscut[u] = 1;
                    for (;;) {
                        pair<int, int> x = S.top(); S.pop();
                        E[bcc_cnt].push_back(id[x]);
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

    void Excalibur(int n) 
    {
        memset(pre, 0, sizeof(pre));
        memset(low, 0, sizeof(low));
        memset(iscut, 0, sizeof(iscut));
        memset(bccno, 0, sizeof(bccno));
        dfs_clock = bcc_cnt = 0;
        
        for (int i = 1; i <= n; i ++) {
            if (pre[i] == 0)
                dfs(i, -1);
        }   
        
        vector<int> ret;
        for (int i = 1; i <= bcc_cnt; i ++) {
            if (bcc[i].size() <= 1) continue;
            if (bcc[i].size() == E[i].size()) {
                for (int j=0;j<E[i].size();j++)
                    ret.push_back(E[i][j]);
            }
        }
        sort(ret.begin(), ret.end());
        printf("%d\n", (int)ret.size());
        for (int i = 0; i < ret.size(); i ++) 
            printf("%d ", ret[i]);
    }
} Saber;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        id[make_pair(u,v)] = id[make_pair(v,u)] = i;
    }
    Saber.Excalibur(n);
}