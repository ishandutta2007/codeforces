#include <iostream>
#include <cstdio>
using namespace std;
int n, m, v[1002];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &v[i]);
    }
    int res = 0;
    for(int i=1;i<=m;i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        res += min(v[x], v[y]);
    }
    cout << res << endl;
}