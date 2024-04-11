#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int NICO = 1000000 + 10;
const LL MOD = 1000000000 + 7;
int par[NICO], n, sum, root;
vector<int> vec[NICO], ans;
int s[NICO], a[NICO], ok=1, gg, gg1;
int dfs(int x, int par)
{
    s[x] = a[x];
    for(int i=0;i<vec[x].size();i++)
    {
        int cur = vec[x][i];
        if(cur == par) continue;
        dfs(cur, x);
        s[x] += s[cur];
    }
    if(s[x] == sum/3 && !gg && x!=root) 
    {
        gg = x;
        ans.push_back(x);
        vector<int> tmp;
        for(int j=0;j<vec[par].size();j++)
        {
            if(vec[par][j] != x)
            {
                tmp.push_back(vec[par][j]);    
            }
        }
        vec[par].clear();
        for(int j=0;j<tmp.size();j++)
        {
            vec[par].push_back(tmp[j]);
        }
    }
    return s[x];
}
int dfs1(int x, int par)
{
    s[x] = a[x];
    for(int i=0;i<vec[x].size();i++)
    {
        int cur = vec[x][i];
        if(cur == par) continue;
        dfs1(cur, x);
        s[x] += s[cur];
    }
    if(s[x] == sum/3 && !gg1 && x != root) 
    {
        gg1 = x;
        ans.push_back(x);
    }
    return s[x];
}
int main() 
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        sum += v;a[i] = v;
        if(u==0) {root = i;continue;}
        vec[u].push_back(i);
        vec[i].push_back(u);
    }
    if(sum%3!=0) ok = 0;
    dfs(root, 0);
    dfs1(root,0);
    if(ans.size() == 2 && ok) printf("%d %d\n", ans[0], ans[1]);
    else printf("-1\n");
}