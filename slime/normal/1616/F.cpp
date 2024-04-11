//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 3
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 605;
int n, m;
int k;

vi cr[maxn];
int flag = 1;
void ins(vi a) {
    for (int i = 1; i <= k; i++) {
        a[i] %= mod;
        if (a[i]) {
            if (i == k) flag = 0;
            if (cr[i][i]) {
                int cc = a[i] * cr[i][i] % 3;
                for (int j = i; j <= k; j++) {
                    a[j] = (a[j] - cc * cr[i][j]) % mod;
                    if (a[j] < 0) a[j] += mod;
                }
            }
            else {
                cr[i] = a;
                break;
            }
        }
    }
}
int a[maxn], b[maxn], c[maxn];
int lb[65][65];
int ans[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        k = m + 1;
        for (int i = 0; i < maxn; i++) cr[i].clear();
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= k; i++) {
            cr[i].resize(k + 1);
            fill(cr[i].begin(), cr[i].end(), 0);
        }
        flag = 1;
        memset(lb, 0, sizeof(lb));
        for (int i = 1; i <= m; i++) {
            cin >> a[i] >> b[i] >> c[i], 
            lb[a[i]][b[i]] = lb[b[i]][a[i]] = i;
            if (c[i] != -1) {
                c[i] %= mod;
                vi cur(k + 1);
                cur[k] = c[i], cur[i] = 1;
                ins(cur);
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                for (int s = j + 1; s <= n; s++) {
                    int u = lb[i][j], v = lb[j][s], w = lb[s][i];
                    
                    if (!u || !v || !w) continue;
                    vi cur(k + 1);

                    cur[u] = 1, cur[v] = 1, cur[w] = 1;
                    ins(cur);
                }
        if (!flag) cout << -1 << endl;
        else {
            for (int j = m; j >= 1; j--) {
                if (cr[j][j]) {
                    int c = 0;
                    for (int u = j + 1; u < k; u++)
                        c += cr[j][u] * ans[u];
                    c = cr[j][k] - c;
                    c %= mod;
                    c *= cr[j][j];
                    c %= mod;
                    if (c <= 0) c += mod;

                    ans[j] = c;
                }
                else ans[j] = 3;
            }
            for (int j = 1; j <= m; j++)
                cout << ans[j] << ' ';
            cout << endl;
        }
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