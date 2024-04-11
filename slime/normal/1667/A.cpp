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
const int maxn = 5005;
int a[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll ans = 1e18;
    for (int i = 1; i <= n; i++) {
        ll cur = 0;
        ll ls = 0;
        for (int j = i + 1; j <= n; j++) {
            ll nd = ((ls + a[j]) / a[j]);
            cur += nd;
            ls = nd * a[j];
        }
        ls = 0;
        for (int j = i - 1; j >= 1; j--) {
            ll nd = ((ls + a[j]) / a[j]);
            cur += nd;
            ls = nd * a[j];
        }
        //cout << i << ' ' << cur << endl;
        chkmin(ans, cur);
    }
    cout << ans << endl;
    return (0-0); //<3
}