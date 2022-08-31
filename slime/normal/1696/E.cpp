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
const int maxn = 500005;
ll jc[maxn], bjc[maxn];
ll c(ll a, ll b) {
    if (b < 0 || b > a) return 0;
    ll ans = jc[a] * bjc[b] % mod * bjc[a - b] % mod;
    return ans;
}
int n, a[maxn];
int main() {
    jc[0] = bjc[0] = 1;
    for (int i = 1; i < maxn; i++) {
        jc[i] = jc[i - 1] * i % mod, 
        bjc[i] = ksm(jc[i], mod - 2);
    }
    cin >> n;
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        ans += c(a[i] + i, i + 1);
        ans %= mod;
    }
    cout << ans << endl;
    
    return (0-0); //<3
}