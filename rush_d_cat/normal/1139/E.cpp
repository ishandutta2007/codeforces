#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 5002;

int n, m, p[N], c[N], d, k[N];
bool us[N]; int match[N];
vector<int> g[N];
bool dfs(int x)
{
    for(int i=0;i<g[x].size();i++)
    {
        if(us[g[x][i]]) continue;
        us[g[x][i]] = 1;
        if(match[g[x][i]] == -1 || dfs(match[g[x][i]]))
        {
            match[g[x][i]] = x; 
            return 1;
        }
    }
    return 0;
}

int hungary(int n)
{
    memset(match, -1, sizeof(match));
    int tot = 0;
    for(int i=0;i<n;i++)
    {
        memset(us, 0, sizeof(us));
        if(dfs(i)) tot ++;
    }
    return tot;
}


int main() {
    scanf("%d%d", &n,&m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &c[i]);
    
    bool vis[N] = {0};
    scanf("%d", &d);
    for (int i = 1; i <= d; i ++)
        scanf("%d", &k[i]), vis[k[i]] = 1;
    
    for (int i = 1; i <= n; i ++)
        if (vis[i] == 0) {
            g[p[i]].push_back(c[i]);
        }

    memset(match, -1, sizeof(match));
    
    int mex = 0, ans[N];
    for (int i = d; i >= 1; i --) {
        
        while(mex < N) {
            memset(us, 0, sizeof(us));
            if (dfs(mex)) mex ++;
            else break;
        }
        ans[i] = mex;
        g[p[k[i]]].push_back(c[k[i]]);
    }

    for (int i = 1; i <= d; i ++)
        printf("%d\n", ans[i]);
}