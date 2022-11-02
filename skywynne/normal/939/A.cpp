#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, NX = 1e9 + 7;
int n, m, r, t, a, b, c, p, A[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
    {
        b = A[i]; c = A[b];
        if (A[c] == i)
            return !printf("YES");
    }
    printf("NO");
    return (0);
}