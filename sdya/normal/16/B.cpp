#include <iostream>

using namespace std;

int n, m;
int a[50], b[50];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
        scanf("%d%d", &a[i], &b[i]);

    for (int i = 1; i <= m; i ++)
        for (int j = i + 1; j <= m; j ++)
            if (b[j] > b[i]) swap(a[i], a[j]), swap(b[i], b[j]);

    int res = 0;
    for (int i = 1; i <= m; i ++)
    {
        res += min(n, a[i]) * b[i];
        n -= min(n, a[i]);
    }
    printf("%d\n", res);
    return 0;
}