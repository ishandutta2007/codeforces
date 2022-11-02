#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N];
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d%d%d%d", &n, &a, &b, &c);
        n /= c;
        printf("%lld\n", n + 1ll * (n / a) * b);
    }
    return (0);
}