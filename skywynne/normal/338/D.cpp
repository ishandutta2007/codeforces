#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10004;
int n, m, k, lcm = 1, rem, A[N];
pair < int , int > Bezo(int a, int b)
{
    if (a % b == 0)
        return (make_pair(0, 1));
    auto ret = Bezo(b, a % b);
    return (make_pair(ret.second, ret.first - a / b * ret.second));
}
int CRT(int a1, int r1, int a2, int r2)
{
    if (abs(r2 - r1) % __gcd(a1, a2))
        return (-4e18);
    int t = a2 / __gcd(a1, a2);
    return (((r2 - r1) / __gcd(a1, a2) * Bezo(a1, a2).first % t + t) % t * a1 + r1);
}
int32_t main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &A[i]);
        if (A[i] / __gcd(lcm, A[i]) * 1.0 * lcm > 1e13)
            return puts("NO");
        lcm *= (A[i] / __gcd(lcm, A[i]));
        if (lcm > n) return puts("NO");
    }
    lcm = A[0];
    for (int i = 1; i < k; i++)
    {
        rem = CRT(lcm, rem, A[i], -i);
        if (rem == -4e18) return puts("NO");
        lcm *= (A[i] / __gcd(A[i], lcm));
    }
    if (!rem) rem = lcm;
    if (rem + k - 1 > m) return puts("NO");
    for (int i = 0; i < k; i++)
        if (__gcd(lcm, rem + i) != A[i])
            return puts("NO");
    return puts("YES");
}