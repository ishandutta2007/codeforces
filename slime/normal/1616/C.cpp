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
const int maxn = 75;
int n, m, k;
int dp[maxn];
int a[maxn];
int fl[maxn][maxn][maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++) {
                    fl[i][j][k] = 0;
                    if ((a[j] - a[i]) * (k - i) == (a[k] - a[i]) * (j - i))
                        fl[i][j][k] = 1;
                }
        int mx = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) {
                int cur = 0;
                for (int k = i; k <= j; k++)
                    if (fl[i][j][k]) cur += 1;
                chkmax(mx, cur);
            }
        cout << n - mx << endl;
    }
    return (0-0); //<3
}