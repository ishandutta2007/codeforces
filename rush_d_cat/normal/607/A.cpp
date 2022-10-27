#include <iostream>
#include <algorithm>
using namespace std;
const int NICO = 100000 + 10;

struct Item 
{
    int a, b;
} it[NICO];

bool cmp(Item A, Item B)
{
    if (A.a == B.a) return A.b < B.b;
    return A.a < B.a;
}

int n, dp[NICO];

int main()
{
    scanf("%d", &n);

    it[0].a = -10000000, it[0].b = 0;
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d %d", &it[i].a, &it[i].b);
    }

    sort(it+1, it+1+n, cmp);

    dp[0] = 0;

    for (int i = 1; i <= n; i ++)
    {
        int lim = it[i].a - it[i].b; // val < lim
        int l = 0, r = i + 1;

        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (it[mid].a < lim)
            {
                l = mid;
            } else {
                r = mid;
            }
        }

        dp[i] = dp[l] + (i - l - 1);
        //printf("%d %d\n", i, dp[i]);
    }

    int mn = NICO;
    for (int i = n; i >= 1; i --)
    {
        mn = min(n - i + dp[i], mn);
    }
    printf("%d\n", mn);
}