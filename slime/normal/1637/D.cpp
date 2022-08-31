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
const int maxn = 105;
int fl[maxn][maxn * maxn];
int a[maxn], b[maxn];
int n;
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll sum = 0, s2 = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i], s2 += a[i] * a[i];
        for (int i = 1; i <= n; i++) cin >> b[i], sum += b[i], s2 += b[i] * b[i];
        memset(fl, 0, sizeof(fl));
        fl[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= (i - 1) * maxn; j++) {
                if (fl[i - 1][j]) fl[i][j + a[i]] = fl[i][j + b[i]] = 1;
            }
        }
        ll ans = 1e18;
        for (int i = 0; i < maxn * maxn; i++) {
            if (fl[n][i]) 
                chkmin(ans, i * i + (sum - i) * (sum - i));
        }
        ans += (n - 2) * s2;
        cout << ans << endl;
    }
    return (0-0); //<3
}