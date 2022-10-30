#include <iostream>

using namespace std;

int d, t, s1, s2;
int a[40], b[40];

int main()
{
    scanf("%d%d", &d, &t);
    for (int i = 1; i <= d; i ++)
        scanf("%d%d", &a[i], &b[i]), s1 += a[i], s2 += b[i];
    if (t >= s1 && t <= s2)
    {
        printf("YES\n");
        for (int i = 1; i <= d; i ++)
        {
            s1 -= a[i], s2 -= b[i];
            for (int j = a[i]; j <= b[i]; j ++)
                if (t - j >= s1 && t - j <= s2)
                {
                    printf("%d ", j);
                    t -= j;
                    break;
                }
        }
    } else printf("NO\n");
    return 0;
}