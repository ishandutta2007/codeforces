#include "stdio.h"
#include <algorithm>

int Solve()
{
    int n;
    scanf("%d", &n);
    for (int m=1; m <=1000; m++)
    {
        int check = n*m+1;
        for (int j=2; j*j <=check; j++)
        {
            if (check % j == 0 && j < check)
            {
                return m;
            }
        }
    }
    return 0;
}

int main()
{
    int cas=1;
//    scanf("%d", &cas);
    for (int i = 0; i < cas; i++)
    {
        int ans = Solve();
        printf("%d\n", ans);
//        printf("Case #%d: %d\n", i+1, ans);
    }
    return 0;
}