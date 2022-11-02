#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e6 + 10;
int n, m, r, k, t;
int main()
{
    scanf("%d%d%d", &n, &k, &t);
    if (t <= k)
        return printf("%d", t), 0;
    if (t <= n)
        return printf("%d", k), 0;
    printf("%d", n + k - t);
    return (0);
}