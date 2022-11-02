#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e6 + 10;
int n, r, t, p, c;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &r);
        t += (r - 1);
        t %= 2;
        if (t % 2)
            printf("1\n");
        else
            printf("2\n");
    }
    return (0);
}