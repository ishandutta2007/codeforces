#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
LL ans = 0;

int a[52][52], n, m;
int row[52], col[52];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }


    for (int i = 1; i <= n; i ++)
    {
        ans += (1LL << (LL)row[i]) - 1;
        ans += (1LL << (LL)(m - row[i])) - 1;
    }

    for (int i = 1; i <= m; i ++)
    {
        ans += (1LL << (LL)col[i]) - 1;
        ans += (1LL << (LL)(n - col[i])) - 1;
    }
    ans -= (m*n);
    cout << ans << endl;

}