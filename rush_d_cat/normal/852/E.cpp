#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int MOD = 1000000007;
int n, deg[100000+10];
int p[100000+10];


int main()
{

    scanf("%d", &n);
    p[0] = 1;
    for (int i = 1; i < n; i ++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        p[i] = p[i-1] * 2 % MOD;
        deg[x] ++, deg[y] ++;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++)
    {
        if(deg[i] == 1) cnt ++;
    }

    LL ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        int temp = (deg[i] == 1) ? (cnt - 1) : cnt;
        ans += p[n - temp];
        ans %= MOD;
    }
    cout << ans << endl;
}