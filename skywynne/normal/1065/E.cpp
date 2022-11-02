#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 2e5 + 10, Mod = 998244353;
int n, m, sgm, A[N], B[N];
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % Mod)
        if (b & 1) ret = 1ll * ret * a % Mod;
    return (ret);
}
int main()
{
    scanf("%d%d%d", &n, &m, &sgm);
    for (int i = 1; i <= m; i++)
        scanf("%d", &B[i]);
    for (int i = 1; i <= m; i++)
        A[i] = B[i] - B[i - 1];
    int tot = 1;
    for (int i = 1; i <= m; i++)
    {
        long long c = 1ll * (Power(sgm, A[i] * 2) - Power(sgm, A[i]) + Mod) * (Mod + 1) / 2;
        c %= Mod; c += Power(sgm, A[i]); c %= Mod;
        tot = 1ll * tot * c % Mod;
    }
    int rst = n - 2 * B[m];
    tot = 1ll * tot * Power(sgm, rst) % Mod;
    printf("%d", tot);
    return (0);
}