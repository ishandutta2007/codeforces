#include<bits/stdc++.h>
using namespace std;
int n, x, y, c;
int main()
{
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1, a; i <= n; i++)
        scanf("%d", &a), c += (a <= x);
    if (x > y) return !printf("%d", n);
    return !printf("%d", (c + 1) >> 1);
}