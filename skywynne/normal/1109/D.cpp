// I'm back b*tches
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 2e6 + 10, Mod = 1e9 + 7;
int n, m, F[N], I[N], Pw[N], Pwm[N];
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1LL * a * a % Mod)
        if (b & 1) ret = 1LL * ret * a % Mod;
    return (ret);
}
inline int NCR(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return (1LL * F[n] * I[r] % Mod * I[n - r] % Mod);
}
inline int Solver(int n, int r)
{
    return NCR(n + r - 1, r - 1);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = F[0] = 1; i < N; i++)
        F[i] = 1LL * F[i -1] * i % Mod;
    I[N - 1] = Power(F[N - 1], Mod - 2);
    for (int i = N - 2; ~i; i--)
        I[i] = I[i + 1] * 1LL * (i + 1) % Mod;
    Pw[0] = 1;
    for (int i = 1; i < N; i++)
        Pw[i] = 1LL * Pw[i - 1] * n % Mod;
    Pwm[0] = 1;
    for (int i = 1; i < N; i++)
        Pwm[i] = 1LL * Pwm[i -1] * m % Mod;

    int tot = 0;
    for (int i = 2; i <= n; i++)
    {
        int tmp = NCR(n - 2, i - 2) * 1LL * F[i - 2] % Mod;
        if (i == n)
            tmp = 1LL * tmp * I[n] % Mod * F[n - 1] % Mod;
        else
            tmp = 1LL * tmp * Pw[n - 1 - i] % Mod;
        tmp = 1LL * tmp * i % Mod;
        tmp = 1LL * tmp * Pwm[n - i] % Mod;
        tmp = 1LL * tmp * Solver(m - i + 1, i - 1) % Mod;
        tot = (tot + tmp) % Mod;
    }
    return !printf("%d\n", tot);
}