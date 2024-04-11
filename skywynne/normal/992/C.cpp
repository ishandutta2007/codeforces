#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, r, t, a, b, c, d, A[N];
int Power(int a, int b)
{
    int ret = 1; a %= Mod;
    for (; b; b >>= 1, a = a % Mod * a % Mod)
        if (b & 1)
            ret = ret * a % Mod;
    return (ret);
}
int32_t main()
{
    cin >> n >> r;
    if (n == 0)
        return !printf("0");
    a = n % Mod;
    b = n % Mod;
    a = a * Power(2, r) % Mod;
    b = b * Power(2, r) % Mod - (Power(2, r) - 1);
    b %= Mod; b += Mod;
    b %= Mod;
    cout << (a + b) % Mod;
    return (0);
}