//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ll unsigned __int128
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
using namespace std;
char s[105];
int n[2];
ll u[2][2005];
int fl[2][2005];
ll gc[2][2005][2005];
ll pre[2][2005][2005];
using i128 = unsigned __int128;
using u64 = unsigned long long;
i128 ctz(i128 x) {
    if (u64(x) == 0)
        return __builtin_ctzll(u64(x >> 64)) + 64;
    else
        return __builtin_ctzll(u64(x));
}
 
i128 gcd(i128 a, i128 b) {
    if (b == 0)
        return a;
 
    int shift = ctz(a | b);
    b >>= ctz(b);
 
    while (a) {
        a >>= ctz(a);
 
        if (a < b)
            swap(a, b);
 
        a -= b;
    }
 
    return b << shift;
}
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return (a / g) * b;
}
ll rdi() {
    scanf("%s", s);
    int l = strlen(s);
    ll res = 0;
    for (int i = 0; i < l; i++)
        res = res * 10 + s[i] - '0';
    return res;
}
 
void ers(int id, int p) {
    int t = id ^ 1;
    for (int j = 0; j < n[t]; j++) {
        if (!fl[t][j]) continue;
        ll fr = 1; 
        if (p) fr = pre[t][j][p - 1];
        if (pre[t][j][p] == fr) continue;
        pre[t][j][p] = fr;
        for (int m = p + 1; m < n[id]; m++) {
            ll cur = pre[t][j][m - 1];
            if (fl[id][m]) 
                cur = lcm(cur, gc[t][j][m]);
            if (cur == pre[t][j][m]) break;
            pre[t][j][m] = cur;
        }
    }
}
void oti(ll a) {
    vector<int> cur;
    while (a) {
        cur.pb(a % 10);
        a = a / 10;
    }
    reverse(cur.begin(), cur.end());
    for (auto v : cur)
        printf("%d", v);
    printf(" ");
}
int upd(int i) {
    int hv = 0;
    vector<int> ot;
    for (int s = 0; s < n[i ^ 1]; s++) 
        if (fl[i ^ 1][s]) ot.pb(s);
    for (int j = 0; j < n[i]; j++) {
        if (!fl[i][j]) continue;
        if (pre[i][j][n[i ^ 1] - 1] != u[i][j]) {
            hv = 1;
            fl[i][j] = 0;
            ers(i, j);
        }
    }
    return hv;
}
int main() {
    int t;
    cin >> t;
    l1:
    while (t--) {
        cin >> n[0] >> n[1];
        memset(fl, 0, sizeof(fl));
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < n[i]; j++)
                u[i][j] = rdi(), fl[i][j] = 1;
        for (int i = 0; i < n[0]; i++)
            for (int j = 0; j < n[1]; j++)
                gc[0][i][j] = gcd(u[0][i], u[1][j]), 
                gc[1][j][i] = gc[0][i][j];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n[i]; j++) {
                ll cur = 1;
                for (int k = 0; k < n[i ^ 1]; k++) {
                    ll tt = gc[i][j][k];
                    cur = lcm(cur, tt);
                    pre[i][j][k] = cur;
                }
            }
        int cnt = 0;
        int tp = 0;
        int tot = 0;
        int hh = 0;
        while (1) {
            tot += 1;
            int s = upd(tp);
            for (int i = 0; i < n[0]; i++)
                for (int j = 0; j < n[1]; j++)
                    if (fl[0][i] && fl[1][j]) hh += i + j;
            if (s == 0) cnt += 1;
            else cnt = 0;
            tp ^= 1;
            if (cnt >= 5) break;
            if ((hh % 213123) & 1) cnt += 1;
        }
        vector<ll> g[2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n[i]; j++)
                if (fl[i][j]) g[i].pb(u[i][j]);
        }
        if (!g[0].size() || !g[1].size()) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << g[0].size() << ' ' << g[1].size() << endl;
        for (int i = 0; i < 2; i++) {
            for (auto v : g[i])
                oti(v);
            printf("\n");
        }
    }
    return (0-0); //<3
}