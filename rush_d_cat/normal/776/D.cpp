#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int NICO = 200000 + 10;
int par[NICO], n, m;
int sta[NICO];
int x, y;
vector<int> v[NICO];
int find(int x)
{
    return (par[x]==-1)?x:(par[x]=find(par[x])); 
}
void unite(int x, int y)
{
    int cx = find(x);
    int cy = find(y);
    if(cx != cy)
    {
        par[cx] = cy;
    }
}
int main()
{
    memset(par, -1, sizeof(par));
    scanf("%d %d", &n, &m);
    int ac = 1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &sta[i]);
        if(sta[i] == 0) ac = 0;
    }
    if(ac) 
    {
        printf("YES\n");
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d", &x);
        while(x--)
        {
            scanf("%d", &y);
            v[y].push_back(i);
        }
    }
    int ok = 1;
    for(int i=1;i<=n;i++)
    {
        int u = v[i][0];
        int v_ = v[i][1];
        if(sta[i] == 1)
        {
            if(find(u) == find(m+v_) || find(v_) == find(m+u)) ok = 0;
            unite(u, v_);
            unite(u+m, v_+m);
        } else {
            if(find(u) == find(v_) || find(u+m) == find(v_+m)) ok = 0;
            unite(u, m+v_);
            unite(v_, m+u);
        }
    }
    cout << (ok?"YES":"NO") << endl;
}