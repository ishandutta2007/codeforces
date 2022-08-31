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
const int maxn = 200005;
ll jc[maxn], bjc[maxn];

ll c(int a, int b) {
    if (a < b) return 0;
    ll ans = jc[a] * bjc[b] % mod * bjc[a - b] % mod;
    return ans;
}
int main() {
    jc[0] = bjc[0] = 1;
    for (int i = 1; i < maxn; i++) {
        jc[i] = jc[i - 1] * i % mod;
        bjc[i] = ksm(jc[i], mod - 2);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ll ans = 1;
        for (int i = 1; (i - 1) * (k - 1) <= n; i++) {
            ans = ans + c(n - (i - 1) * (k - 1), i) * ksm(c(n, i), mod - 2) % mod;
            ans %= mod;
        }
        if (ans < 0) ans += mod;
        cout << ans << endl;
    }
    return 0;
}