#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e6 + 10;
int n, r, t, p, c, A[MXN], Mn = 1e9;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
    {
        for (int h = i; h <= j; h++)
            r += A[h];
        Mn = min(abs(r - (360 - r)), Mn);
        r = 0;
    }
    printf("%d", Mn);
    return (0);
}