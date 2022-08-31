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
const int maxn = 1003;
#define bs bitset<1005>
int a[maxn][maxn];
bs r[maxn][maxn];
bs cur;
bs tt[maxn]; int cnt = 0;
int res[maxn][maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                scanf("%d", &a[i][j]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                r[i][j].reset(), 
                res[i][j] = 0;
        }
        for (int i = 1; i <= n; i++)
            r[1][i][i] = 1;
        int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                cur.reset();
                for (int l = 0; l < 4; l++) {
                    int ei = i + mv[l][0], ej = j + mv[l][1];
                    if (ei <= 0 || ej <= 0 || ei > n || ej > n) continue;
                    cur ^= r[ei][ej];
                }
                cur[n + 1] = cur[n + 1] ^ 1;
                if (i != n) r[i + 1][j] = cur;
                else tt[cnt++] = cur;
            }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (tt[j][i]) {
                    swap(tt[j], tt[i]);
                    break;
                }
                for (int s = 1; s <= n; s++) {
                    if (s == i) continue;
                    if (tt[s][i]) tt[s] ^= tt[j];
                }
            }
        }
        for (int i = 1; i <= n; i++)
            res[1][i] = tt[i][n + 1];
        for (int i = 1; i < n; i++)
            for (int j = 1; j <= n; j++) {
                int cur = 0;
                for (int l = 0; l < 4; l++) {
                    int ei = i + mv[l][0], ej = j + mv[l][1];
                    if (ei <= 0 || ej <= 0 || ei > n || ej > n) continue;
                    cur ^= res[ei][ej];
                }
                cur ^= 1;
                res[i + 1][j] = cur;
            }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (res[i][j]) ans ^= a[i][j];
        cout << ans << endl;
    }
    return (0-0); //<3
}