#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100000 + 10;
const int inf = 1000000000 + 10;
vector<int> vec1[maxn], vec2[maxn];
bool used[maxn];
int st[maxn];
int main()
{
    int n, m, k, i, j, x, y, cost;
    cin >> n >> m >> k;
    for(i = 1; i <= m; i++)
    {
        cin >> x >> y >> cost;
        vec1[x].push_back(cost);
        vec1[y].push_back(cost);
        vec2[x].push_back(y);
        vec2[y].push_back(x);
    }
    int res = inf;
    for(i = 1; i <= k; i++)
    {
        cin >> x;
        st[i] = x;
        used[x] = 1;
    }
    for(i = 1; i <= k; i++)
    {
        x = st[i];
        int sz = vec2[x].size();
        for(j = 0; j < sz; j++)
        {
            if(!used[vec2[x][j]] && vec1[x][j] < res) res = vec1[x][j];
        }
    }
    if(res == inf) cout << -1;
    else cout << res;

    return 0;
}