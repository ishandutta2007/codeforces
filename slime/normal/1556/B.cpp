//Awwawa! Dis cold yis ratten buy Pikachu!
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
const int maxn = 200005;
int a[maxn];
int n;
int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        int cnt[2] = {0, 0};
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), a[i] %= 2, cnt[a[i]] += 1;
        ll ans = 1e18;
        for (int tp = 0; tp < 2; tp++) {
            if (cnt[tp] != (n + 1) / 2) continue;
            // tp : first
            int g[2] = {0, 0};
            ll na = 0;
            for (int i = 1; i <= n; i++) {
                g[a[i]] += 1;
                if (a[i] == tp) {
                    int cr = g[tp] - 1;
                    na += abs(cr - g[tp ^ 1]);
                }
            }
            chkmin(ans, na);
        }
        if (ans > 1e12) ans = -1;
        printf("%lld\n", ans);
    }
    return (0-0); //<3
}