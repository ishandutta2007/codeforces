//
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 4000005;
ll fac[maxn], ifac[maxn];
ll c(int a, int b) {
    if (a < b || b < 0) return 0;
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}
ll cur[maxn], ans[maxn];
int main() {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < maxn; i++)
        fac[i] = fac[i - 1] * i % mod;
    ifac[maxn - 1] = ksm(fac[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; i--)
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= 3 * n + 3; i++)
        ans[i] = c(3 * n + 3, i + 1);
    ll u = 3, v = 3, w = 1;
    ll rv = (mod + 1) / 3;
    for (int i = 0; i <= 3 * n; i++) {
        cur[i] = rv * ans[i] % mod;
        ans[i + 1] = (ans[i + 1] - 3 * cur[i]) % mod;
        ans[i + 2] = (ans[i + 2] - cur[i]) % mod;
        if (cur[i] < 0) cur[i] += mod;
    }
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", cur[x]);
    }
    return (0-0); //<3
}