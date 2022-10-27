#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
const int NICO = 200002;
const int MOD = 1e9 + 7;
int n, cx, cy, cnt; ll res, res_ = 1;
int pre[NICO], used[NICO], dis[NICO];
int par[NICO], pow[NICO];
vector<int> vec[NICO];
int find(int x)
{
    if(par[x] == -1) return x;
    return par[x] = find(par[x]);
}


void getDis(int x)
{
    for(int i=1;i<=n;i++) used[i] = 0;
    queue<int> q;
    used[x] = 1;
    dis[x] = 0;
    q.push(x);
    while(!q.empty())
    {
        int tmp = q.front();q.pop();
        int sz = (int)vec[tmp].size();
        for(int i=0;i<sz;i++)
        {
            if(!used[vec[tmp][i]])
            {
                used[vec[tmp][i]] = 1;
                dis[vec[tmp][i]] = dis[tmp] + 1;
                q.push(vec[tmp][i]);
            }
        }
    }
}

void unite(int x, int y)
{
    int t1 = find(x);
    int t2 = find(y);
    if(t1 != t2)
    {
        par[t1] = t2;
        vec[x].push_back(y);
        vec[y].push_back(x);
    } else {
        cx = x;
        cy = y;
        getDis(cx);
        int d = dis[cy] + 1;
        if(d > MOD) d = 2;
        cnt += d;
        res_ = res_ * (pow[d] - 2) % MOD;
    }
}


int main()
{
    scanf("%d", &n);
    pow[0] = 1;
    for(int i=1;i<NICO;i++)
    {
        pow[i] = pow[i-1] * 2 % MOD;
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &pre[i]);
    }
    for(int i=1;i<=n;i++) par[i] = -1, dis[i] = MOD;
    for(int i=1;i<=n;i++) unite(i, pre[i]);
    res = pow[n-cnt];
    res = (res * res_) % MOD;
    cout << res << endl;
}