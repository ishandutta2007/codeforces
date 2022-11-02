#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n,q, r, t, a, b, c, d, A[N];
long long m;
int main()
{
    scanf("%d%lld", &n, &m);
    int Mn = n, Mx = 0;
    for (int i = 0; i <= n; i++)
        if (1ll * i * (i - 1) / 2 >= m)
        {
            Mx = n - i;
            break;
        }
    if (m >= (n + 1) / 2)
        Mn = 0;
    else
        Mn = n - m * 2;
    printf("%d %d\n", Mn, Mx);
    return (0);
}