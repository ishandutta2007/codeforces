#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> mp;
int n, a[100000+10], b[100000+10];
int vis[100000+10], cnt = 1;
vector<int> vec[100000+10];

void dfs(int u)
{
    if(vis[u] == 1) return;
    //printf("%d\n", u);
    vis[u] = 1;

    vec[cnt].push_back(u);
    int v = mp[ a[u] ]; 
    dfs(v);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i ++)
    {
        mp[ b[i] ] = i;
    }

    for (int i = 1; i <= n; i ++)
    {
        dfs(i);
        if (vec[cnt].size() >= 1) 
        {
            cnt ++;
        }
    }

    cnt --;
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i ++)
    {
        printf("%d ", vec[i].size());
        for(int j = 0; j < vec[i].size(); j ++)
        {
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
}