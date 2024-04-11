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
const int maxn = 2015;
ll dp[maxn][maxn];
int main() {
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j <= i; j++) {
            if (j == i) dp[i][j] = i;
            else {
                if (j == 0) dp[i][j] = 0;
                else {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) * (mod + 1) / 2;
                    dp[i][j] %= mod;
                }
            }
        }
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        ll ans = dp[n][m] * k % mod;
        cout << ans << endl;
    }
    return (0-0); //<3
}