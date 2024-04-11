 #include <iostream>
#include <vector> 
#include <cstdio>
using namespace std;
const int NICO = 100002;
int n;
int deg[NICO];
int leg[NICO];
int die[NICO];
vector<int> vec[NICO];
void dfs(int x, int par)
{
    if(deg[x] >= 3)
    {
        leg[x] ++;
        return;
    }
    die[x] = 1;
    for(int i=0;i<vec[x].size();i++)
    {   
        if(vec[x][i] != par)
        {
            dfs(vec[x][i], x);
        }
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i] == 1)
        {
            dfs(i, 0);
        }
    }
    int ok = 1;
    for(int i=1;i<=n;i++)
    {
        int cnt = 0;
        if(!die[i])
        {
            for(int j=0;j<vec[i].size();j++)
            {
                //cout << vec[i][j] << " " << deg[vec[i][j]] << " " << leg[vec[i][j]] << endl;
                if(!die[vec[i][j]] && deg[vec[i][j]] - min(leg[vec[i][j]], 2) > 1)
                {
                    cnt ++;
                }
            }
        }
        if(cnt >= 3) ok = 0;
    }
    printf("%s\n", ok?"Yes":"No");
}