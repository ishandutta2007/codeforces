#include <cstdio>
int mx(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int n;
    int x, y;
    int ans = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        ans = mx(ans, x + y);
    }

    printf("%d\n", ans);
    return 0;
}
///