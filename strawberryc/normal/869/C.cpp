#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
using namespace std;
const int N = 5005, PYZ = 998244353;
int a, b, c, fac[N], inv[N], ans1, ans2, ans3;
int A(int n, int m) {
    return 1ll * fac[n] * inv[n - m] % PYZ;
}
int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % PYZ * inv[n - m] % PYZ;
}
int main() {
    int i; cin >> a >> b >> c; fac[0] = 1;
    For (i, 1, 5000) fac[i] = 1ll * fac[i - 1] * i % PYZ;
    inv[0] = inv[1] = 1;
    For (i, 2, 5000)
        inv[i] = 1ll * (PYZ - PYZ / i) * inv[PYZ % i] % PYZ;
    For (i, 2, 5000) inv[i] = 1ll * inv[i] * inv[i - 1] % PYZ;
    For (i, 0, min(a, b))
        ans1 = (ans1 + 1ll * C(a, i) * A(b, i) % PYZ) % PYZ;
    For (i, 0, min(a, c))
        ans2 = (ans2 + 1ll * C(a, i) * A(c, i) % PYZ) % PYZ;
    For (i, 0, min(b, c))
        ans3 = (ans3 + 1ll * C(b, i) * A(c, i) % PYZ) % PYZ;
    cout << 1ll * ans1 * ans2 % PYZ * ans3 % PYZ << endl;
    return 0;
}