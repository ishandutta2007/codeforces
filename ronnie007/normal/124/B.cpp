#include <stdio.h>
#include <algorithm>
using namespace std;

#define inf 1000000000

int a[17][17];
int n, k;
int p[17];
int ans;

int main()
    {
    scanf("%d %d\n", &n, &k);
    for (int i = 0; i < n; i++)
        {
        for (int j = 0; j < k; j++)
            {
            char c;
            scanf("%c", &c);
            a[i][j] = c - '0';
            }
        scanf("\n");
        }

    for (int i = 0; i < k; i++)
        {
        p[i] = i;
        }

    ans = inf;
    do
        {
        int mi = inf, ma = -inf;
        for (int i = 0; i < n; i++)
            {
            int x = 0;
            for (int j = 0; j < k; j++)
                (x *= 10) += a[i][p[j]];
            ma = max(ma, x);
            mi = min(mi, x);
            }
        ans = min(ans, ma - mi);
        }while (next_permutation(p, p + k));

    printf("%d\n", ans);
    return 0;
    }