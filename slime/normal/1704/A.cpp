// Awwawa! Dis cold yis ratten buy Pikachu!
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
const int maxn = 55;
char s[maxn], t[maxn];
int dp[2][maxn];
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j < 2; j++) {
                dp[j][i] = 0;
                if (n - i + 1 == m) {
                    int flag = 1;
                    for (int k = 1; k <= m; k++) {
                        int nd = (int)t[k] - '0';
                        int cr = s[i + k - 1] - '0';
                        if (k == 1) cr = j;
                        if (cr != nd) {
                            flag = 0;
                            break;
                        }
                    }
                    dp[j][i] = flag;
                }
                else if (n - i + 1 > m)
                {
                    for (int u = 0; u < 2; u++) {
                        if (u != j && u != s[i + 1] - '0') continue;
                        dp[j][i] |= dp[u][i + 1];
                    }
                }
            }
        }
        int ans = dp[s[1] - '0'][1];
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
    return (0-0); //<3
}