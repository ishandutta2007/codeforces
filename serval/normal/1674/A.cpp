#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y;
    scanf("%d%d", &x, &y);
    if (y % x == 0)
        printf("%d %d\n", 1, y / x);
    else
        printf("0 0\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}