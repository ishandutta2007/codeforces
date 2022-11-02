#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, k, c, d, A[N];
int main()
{
    scanf("%d%d", &n, &k); b = k;
    for (int i = 0; i < n; i++)
        scanf("%d", &a), a %= k, b = __gcd(b, a);
    for (int i = 0; i < k; i++)
        if (i % b == 0)
            c ++;
    printf("%d\n", c);
    for (int i = 0 ; i < k; i++)
        if (i % b == 0)
            printf("%d ", i);
    return (0);
}