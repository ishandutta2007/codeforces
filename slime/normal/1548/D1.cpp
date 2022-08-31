//
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
const int maxn = 6005;
int x[maxn], y[maxn];
int main() {
    int n;
    cin >> n;
    int cnt[4] = {0, 0, 0, 0};
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        x[i] /= 2, y[i] /= 2;
        cnt[2 * (x[i] % 2) + (y[i] % 2)] += 1;
    }
    ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            for (int k = j + 1; k < 4; k++)
                ans -= 1ll * cnt[i] * cnt[j] * cnt[k];
    cout << ans << endl;
    return (0-0); //<3
}