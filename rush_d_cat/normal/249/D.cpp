#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define N (100000+10)
const double EPS = 1e-10;
const double INF = 1e10;
typedef long long LL;

LL n, x[N], y[N], dp[N];
LL a, b, c, d;
struct Item 
{
    LL l, r;
    int id;
} item[N];
bool cmp(Item A, Item B) 
{
    if ( A.l == B.l )
    {
        return A.r > B.r;
    }
    return A.l < B.l;
}
int main()
{

    scanf("%lld", &n);
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    for (int i = 1; i <= n; i ++) 
    {
        scanf("%lld %lld", &x[i], &y[i]);
    }

    int tot = 0;

    for (int i = 1; i <= n; i ++) 
    { 
        LL right = y[i] * b - x[i] * a; 
        LL left =  y[i] * d - x[i] * c;

        if (left < 0 && right > 0)
        {
            item[++tot].id = i;
            item[tot].l = - left;
            item[tot].r = right;
            //printf("point: %d, px: %lld, py: %lld, l:%lld, r:%lld\n", i, x[i], y[i], item[i].l, item[i].r);
        }
    }

    sort(item + 1, item + 1 + tot, cmp);

    for (int i = 1; i <= tot; i ++)
    {
        int t = item[i].id;
        //printf("point: %lld, px: %lld, py: %lld, l:%lld, r:%lld\n", t, x[t], y[t], item[i].l, item[i].r);
    }

    int cnt = 0;

    for (int i = 1; i <= n; i ++) 
    {
        if (item[i].r > dp[cnt]) 
        {
            dp[++cnt] = item[i].r;
            continue;
        }

        int pos = lower_bound(dp + 1, dp + cnt, item[i].r) - dp;
        dp[pos] = item[i].r;
    }

    printf("%d\n", cnt);


}