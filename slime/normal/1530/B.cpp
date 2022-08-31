//Awwawa! Dis cold yis ratten buy tEMMIE!
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
const int maxn = 55;
char inp[maxn][maxn];
int res[maxn][maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n <= 2 || m <= 2) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (i % 2 && j % 2) printf("1");
                    else printf("0");
                }
                printf("\n");
            }
        }
        else {
            memset(res, 0, sizeof(res));
            res[1][1] = res[1][m] = res[n][m] = res[n][1] = 1;
            for (int j = 3; j + 1 < m; j += 2)
                res[1][j] = res[n][j] = 1;
            for (int j = 3; j + 1 < n; j += 2)
                res[j][1] = res[j][m] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    printf("%d", res[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}