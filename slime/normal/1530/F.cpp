#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 31607
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int n;
int dp[1 << 21];
int e[1 << 21];
void upd_1(int p, int c) {
    for (int j = 0; j < (1 << n); j += (1 << (p + 1))) {
        for (int i = j; i < j + (1 << p); i++) {
            assert((i | (1 << p)) != i);
            dp[i | (1 << p)] = (dp[i | (1 << p)] + c * dp[i]) % mod, 
            dp[i] = dp[i] * (1 - c) % mod;
        }
    }
}
const int maxn = 22;
int ban[maxn][maxn];
int rem[maxn][maxn];
int cr[maxn];
int er[maxn];
int ans = 0;
void dfs(int x, int we) {
    if (x == n) {
        int res = 1;
        for (int i = 0; i < n; i++)
            res = res * (1 - cr[i]) % mod;
        res = res * we % mod;
        ans = (ans + res) % mod;
        return ;
    }
    dfs(x + 1, we * er[x] % mod);
    int g[maxn];
    for (int i = 0; i < n; i++) g[i] = cr[i];
    for (int i = 0; i < n; i++)
        cr[i] = cr[i] * rem[x][i] % mod;
    dfs(x + 1, we);
    for (int i = 0; i < n; i++)
        cr[i] = g[i];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            cin >> ban[i][j]; 
            ban[i][j] *= ksm(10000, mod - 2);
            ban[i][j] %= mod;
            ban[i][j] = 1 - ban[i][j];
        }
    int fn = 0;
    for (int s = 0; s < 4; s++) {
        int wei = 1;
        for (int i = 0; i < n; i++) {
            int nu = 1;
            for (int j = 0; j < n; j++) {
                int ers = 0;
                if ((s & 1) && (j == i)) ers = 1;
                if ((s & 2) && (j == n - 1 - i)) ers = 1;
                if (ers) {
                    rem[i][j] = 1;
                    wei = wei * (1 - ban[i][j]) % mod;
                }
                else {
                    rem[i][j] = 1 - ban[i][j];
                    nu = nu * rem[i][j] % mod;
                }
            }
            er[i] = -nu;
            /*
            for (int j = 0; j < (1 << n); j++) 
                dp[j] = (dp[j] - e[j] * nu) % mod;
            */
        }
        ans = 0;
        for (int i = 0; i < n; i++) cr[i] = 1;
        dfs(0, 1);
        int res = ans * wei % mod;
        if (s == 0 || s == 3) fn += res;
        else fn -= res;
    }
    fn = 1 - fn;
    fn %= mod;
    if (fn < 0) fn += mod;
    cout << fn << endl;
    return 0;
}
/*
2
5000 5000
5000 5000
*/