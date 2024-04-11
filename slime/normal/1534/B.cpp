#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 4000005;
int a[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        a[n + 1] = 0;
        for (int i = 1; i <= n + 1; i++)
            ans += abs(a[i] - a[i - 1]);
        for (int i = 1; i <= n; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
                ans -= a[i] - max(a[i - 1], a[i + 1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}