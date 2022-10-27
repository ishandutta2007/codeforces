#include <iostream>
#include <cstring>
using namespace std;
int n;
int x[102], y[102];
int par[102];
int find(int x)
{
    if(par[x] == -1) return x;
    return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    int cx = find(x);
    int cy = find(y);
    if(cx!=cy)
    {
        par[cx] = cy;
    }
}
int main()
{
    cin >> n;
    memset(par, -1, sizeof(par));
    for(int i=1;i<=n;i++)
    {
        cin >> x[i] >> y[i];
        for(int j=1;j<i;j++)
        {
            if(x[j] == x[i] || y[j] == y[i])
            {
                unite(i, j);
            }
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++)
    {
        if(i==find(i)) res ++;
    }
    res = max(res-1, 0);
    cout << res << endl;
}