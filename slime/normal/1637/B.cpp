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
#define maxn 105
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
#define str string
int dp[maxn][maxn];
int mx[maxn][maxn];
int a[maxn], fl[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) {
                memset(fl, 0, sizeof(fl));
                for (int k = i; k <= j; k++)
                    if (a[k] < maxn) fl[a[k]] = 1;
                mx[i][j] = 0;
                while (fl[mx[i][j]]) mx[i][j] += 1;
            }
        int ans = 0;
        for (int i = n; i >= 1; i--)
            for (int j = i; j <= n; j++) {
                dp[i][j] = 0;
                for (int k = i; k <= j; k++) {
                    chkmax(dp[i][j], mx[i][k] + 1 + dp[k + 1][j]);
                }
                ans += dp[i][j];
            }
        cout << ans << endl;
    }
    return (0-0); //<3
}