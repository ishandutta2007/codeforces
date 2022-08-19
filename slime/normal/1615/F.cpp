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
const int maxn = 4005;
const int pls = 2005;
ll w[2005][maxn];
ll t[2005][maxn]; // ways
char s[maxn], tt[maxn];
int main() {
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        scanf("%s", s + 1);
        scanf("%s", tt + 1);
        for (int i = 1; i <= n + 1; i++)
            for (int j = pls - n; j <= pls + n; j++)
                w[i][j] = 0, t[i][j] = 0;
        w[1][pls] = 0, t[1][pls] = 1;
        for (int i = 1; i <= n; i++) {
            int cnt[3] = {0, 0, 0};
            for (int m = 0; m < 2; m++)
                for (int u = 0; u < 2; u++) {
                    if (s[i] != '?' && m != s[i] - '0') continue;
                    if (tt[i] != '?' && u != tt[i] - '0') continue;
                    int ntp = 0;
                    if (m == u) ntp = 1;
                    else ntp = (m ^ (i & 1)) * 2;
                    cnt[ntp] += 1;
                }
            for (int u = 0; u < 3; u++) {
                if (!cnt[u]) continue;
                for (int j = pls - i; j <= pls + i; j++) {
                    int nw = 0, nj = j;
                    int cur = j - pls;
                    if (u == 0) {
                        nj = j + 1;
                        if (cur >= 0) nw = -i;
                        else nw = i;
                    }
                    else if (u == 2) {
                        nj = j - 1;
                        if (cur <= 0) nw = -i;
                        else nw = i;
                    }
                    int we = cnt[u];
                    t[i + 1][nj] = (t[i + 1][nj] + 1ll * t[i][j] * we) % mod;
                    w[i + 1][nj] = (w[i + 1][nj] + we * (w[i][j] + 1ll * t[i][j] * nw)) % mod;
                }
            }
        }
        ll ans = w[n + 1][pls];
        ans %= mod;
        if (ans < 0) ans += mod;
        cout << ans << endl;
    }
    return (0-0); //<3
}
/*
1

4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19*/