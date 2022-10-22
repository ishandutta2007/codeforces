#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int maxs = 3e5+10;
const int mod = 998244353;
int pow(int x, int u) {
    int y = 1;
    for (; u; u>>=1, x = 1LL * x * x %mod) if (u&1) y = 1LL * y * x %mod;
    return y;
}
int n, a[maxn], p[maxs], q[maxs];
int main() {
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++)  cin >> a[i], s += a[i];
    p[0] = q[1] = n - 1;
    for (int i = 1; i < s; i++){
        p[i] = (s + 1LL * i * p[i-1]) % mod * pow(s-i, mod - 2) % mod * (n-1) %mod; 
        q[i+1] = (q[i] + p[i]) % mod; 
    }
    long long Ans = -1LL * (n-1) * q[s] % mod;
    for (int i = 1; i <= n; i++)
        Ans += q[s] - q[a[i]];
    Ans = Ans % mod * pow(n, mod-2) % mod;
    if (Ans < 0) Ans += mod;
    cout << Ans << endl;
    return 0;
}