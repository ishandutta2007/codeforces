//Awwawa! Dis cold yis ratten buy Pikachu!
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
const int maxn = 1000015;
ll jc[maxn], bjc[maxn];

ll cur[maxn];
ll cal(int n, int m) {
    for (int j = 0; j <= n; j++)
        cur[j] = jc[n] * bjc[j] % mod * bjc[n - j] % mod;
    for (int j = 1; j <= n; j++)
        cur[j] = (cur[j] + cur[j - 1]) % mod;
    for (int j = 1; j <= n; j++)
        cur[j] = (cur[j] + cur[j - 1]) % mod;  
    ll ans = cur[m - 1] * ksm((mod + 1) / 2, n - 1) % mod;
    return ans; 
}
int main() {
    jc[0] = 1; bjc[0] = 1;
    for (int i = 1; i < maxn; i++)
        jc[i] = jc[i - 1] * i % mod, 
        bjc[i] = ksm(jc[i], mod - 2);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        ll ans = cal(n, m) * k % mod;
        cout << ans << endl;
    }
    return (0-0); //<3
}