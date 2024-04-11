#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 100005
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int n;
int main() {
    cin >> n;
    ll ans = ksm(3, 3 * n);
    int cnt = 0;
    // 1, 1, 1
    // 2, 1, 0 -> 6
    ans -= ksm(7, n);
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}