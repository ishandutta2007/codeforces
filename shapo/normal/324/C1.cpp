#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;


#define maxn 1005000

int ans[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    ans[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = i;
        for (int j = 1; j <= i; j *= 10)
        {
            int cur = (i / j % 10);
            if (cur != 0)
            {
                ans[i] = min(ans[i], ans[i - cur] + 1);
            }
        }
    }
    printf("%d\n", ans[n]);
    return 0;
}