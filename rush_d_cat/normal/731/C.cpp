#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
using namespace std;
const int MAXN = 200000 + 10;
int par[MAXN], c[MAXN];
vector<int> vec[MAXN];
map<int, int> mp;
int n, m, k;
int find(int x)
{
    if(par[x] == -1) return x;
    return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    int x_ = find(x);
    int y_ = find(y);
    if(x_ != y_)
    {
        par[x_] = y_;
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    int i, j;
    for(i = 1; i <= n; i++) par[i] = -1;
    for(i = 1; i <= n; i++) scanf("%d", &c[i]);
    for(i = 1; i <= m; i++)
    {
        int l, r;scanf("%d %d", &l, &r);
        unite(l, r);
    }
    for(i = 1; i <= n; i++)
    {
        int t = find(i);
        vec[t].push_back(i);
    }
    int res = 0;
    for(i = 1; i <= n; i++)
    {
        mp.clear();
        int sz = vec[i].size();
        if(sz <= 1) continue;
        int max_ = 0;
        for(j = 0; j < sz; j++)
        {
            mp[c[vec[i][j]]]++;
        }
        map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();++it)
        {
            if(it->second > max_) max_ = it->second;
        }
        res += sz - max_;
    }
    cout << res << endl;
}