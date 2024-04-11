                            
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
map<ll, int> mp;
set<int> st;
set<ll> st_;
ll a[100002], b[100002], ans[100002] ,res[100002];
int par[100002], used[100002];
int find(int x)
{
    if(par[x] == -1) return x;
    return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    int x_ = find(x);
    int y_ = find(y);
    if (x_ != y_)
    {
        par[x_] = y_;
        ans[y_] += ans[x_];
    }
}
int main()
{
    int n, i;
    cin >> n;
    for(i = 1; i <= n; i++) cin >> a[i];
    for(i = 1; i <= n; i++) cin >> b[i];
    memset(used, 0, sizeof(used));
    memset(par, -1, sizeof(par));
    memset(ans, 1, sizeof(ans));
    memset(res, 0, sizeof(res));
    for(i = n; i >= 1; i--)
    {
        int x = b[i];
        used[x] = 1;
        ans[x] = a[x];
        if(used[x+1] && used[x-1])
        {
            unite(x + 1 ,x);
            unite(x - 1, x);
        } else if (used[x+1]) {
            unite(x + 1, x);
        } else if (used[x-1]) {
            unite(x - 1, x);
        }
        res[i-1] = max(res[i], ans[x]);
    }
    for(i = 1; i <= n; i++)
    {
        printf("%I64d\n", res[i]);
    }
}