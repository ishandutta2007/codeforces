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
const int maxn = 200015;
int t;
int a[maxn];
ll s[maxn];
int dp[maxn][4]; // 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        cin >> x;
        for (int i = 1; i <= n; i++) 
            a[i] -= x;
        for (int i = n + 1; i >= 1; i--)
            for (int j = 0; j < 3; j++) {
                if (i == n + 1) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i + 1][0];
                    ll cur = a[i];
                    int fl = 1;
                    for (int m = 0; m <= j; m++) {
                        if (m != 0 && cur < 0) 
                            fl = 0;
                        if (i - 1 - m >= 0)
                            cur += a[i - 1 - m];
                    }
                    if (fl) 
                        chkmax(dp[i][j], dp[i + 1][min(2, j + 1)] + 1);
                }
            }
        cout << dp[1][0] << endl;
    }
    return (0-0); //<3
}