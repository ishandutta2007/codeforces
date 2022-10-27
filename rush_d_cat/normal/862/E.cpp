#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;

#define N 100002
int n, m, q;
int a[N], b[N];

LL sum[N], tot = 0;


void sol(LL ans)
{
    LL res = 1e18;

    LL pos1 = lower_bound(sum + 1, sum + 1 + m - n + 1, ans) - sum; 

    LL pos2 = pos1 - 1;

    if (pos1 > m - n + 1) pos1 = m - n + 1;
    if (pos1 < 1) pos1 = 1;

    if (pos2 > m - n + 1) pos2 = m - n + 1;
    if (pos2 < 1) pos2 = 1;

    res = min(res, abs(ans - sum[pos1]));
    res = min(res, abs(ans - sum[pos2]));
    printf("%lld\n", res);

}


int main()
{
    
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i ++)
    {
        tot += i % 2 ? a[i] : (- a[i]);
    }

    for (int i = 1; i <= m; i ++)
    {
        scanf("%d", &b[i]);
    }

    for (int i = 1; i <= n; i ++)
    {
        sum[1] += (i % 2) ? b[i] : (- b[i]);
    }
    for (int i = 2; i <= n + 1; i ++)
    {
        sum[2] += (i % 2) ? (- b[i]) : b[i];
    }

    for (int i = 3; i <= m - n + 1; i ++)
    {
        if (n % 2 == 0)
            sum[i] = sum[i - 2] + (b[i + n - 2] - b[i + n - 1]) - (b[i - 2] - b[i - 1]);
        else
            sum[i] = sum[i - 2] + (b[i + n - 1] - b[i + n - 2]) - (b[i - 2] - b[i - 1]);
    }

    sort(sum + 1, sum + 1 + m - n + 1);


    LL l, r, x;

    sol(tot);

    for (int i = 1; i <= q; i ++)
    {
        scanf("%lld %lld %lld", &l, &r, &x);
        tot += x * ( ( (r+1)/2 - l/2 ) - ( r/2 - (l-1)/2 ) ); 
        sol(tot);
    }


}