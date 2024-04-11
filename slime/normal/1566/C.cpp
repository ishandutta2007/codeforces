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
const int maxn = 100005;
int f[3];
int r[2][maxn];
int dp[maxn];
char inp[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < 2; j++) {
            scanf("%s", inp + 1);
            for (int k = 1; k <= n; k++)
                r[j][k] = inp[k] - '0';
        }
        dp[n + 1] = 0;
        f[0] = f[1] = f[2] = n + 1;
        for (int i = n; i >= 1; i--) {
            chkmin(f[r[0][i]], i);
            chkmin(f[r[1][i]], i);
            dp[i] = dp[i + 1];
            int cr = i;
            for (int j = 0; j < 3; j++) {
                if (cr > n) break;
                chkmax(dp[i], dp[cr + 1] + j);
                chkmax(cr, f[j]);
            }
        }
        printf("%d\n", dp[1]);
    }
    return (0-0); //<3
}