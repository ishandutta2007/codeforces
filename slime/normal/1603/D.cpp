//Awwawa! Dis cold yis ratten buy Pikachu!
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
const int maxn = 100005;
vi fc[maxn];
vi tt[maxn];

ll cc[maxn];
ll ans = 0;
ll cnt[maxn];
int l, r;
void init(int pl) {
    for (auto v : fc[pl]) cc[v] = 0;
    for (auto v : fc[pl]) {
        cc[v] += pl / v;
        for (auto s : fc[v]) {
            if (s == v) continue;
            cc[s] -= cc[v];
        }
    }
    for (auto v : fc[pl]) {
        tt[pl].pb(cc[v]);
        //cout << pl << ' ' << v << ' ' << cc[v] << endl;
    }
}
void ins(int pl, int tp) {
    for (int i = 0; i < fc[pl].size(); i++) {
        cnt[fc[pl][i]] += tp * tt[pl][i];
        if (fc[pl][i] >= l) ans += tp * tt[pl][i];
    }
}

void mv(int a, int b) {
    while (l > a) {
        l -= 1;
        ans += cnt[l];
    }
    while (r < b) {
        r += 1;
        ins(r, 1);
    }
    while (l < a) {
        ans -= cnt[l]; l += 1;
    }
    while (r > b) {
        ins(r, -1);
        r -= 1;
    }
}
ll dp[20][maxn * 2];
void calc(int t, int al, int ar, int bl, int br) {
    if (bl > br) return ;
    int bm = (bl + br) >> 1;
    ll nans = 1e18; int pl = -1;
    for (int j = al; j <= ar; j++) {
        mv(j + 1, bm);
        if (chkmin(nans, ans + dp[t - 1][j])) pl = j;
    }
    chkmin(dp[t][bm], nans);
    calc(t, al, pl, bl, bm - 1);
    calc(t, pl, ar, bm + 1, br);
}
int main() {
    for (int i = maxn - 1; i >= 1; i--)
        for (int j = i; j < maxn; j += i)
            fc[j].pb(i);
    for (int i = 1; i < maxn; i++) 
        init(i);
    
    l = 1, r = 1; cnt[1] += 1;
    ans = 1;
    // while (1) {
    //     int a, b;
    //     cin >> a >> b;
    //     mv(a, b);
    //     cout << ans << endl;
    // }
    for (int i = 1; i < 17; i++) {
        if (i == 1) {
            for (int j = 1; j < maxn; j++) {
                mv(1, j);
                dp[i][j] = ans;
            }
        }
        else {
            for (int j = 1; j < maxn; j++) 
                dp[i][j] = dp[i - 1][j / 2] + (j - j / 2);
            for (int j = 1; j < maxn; j <<= 1) 
                calc(i, 1, j, j + 1, min(maxn - 1, 2 * j));
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        ll ans = 0;
        if (k >= 17) ans = n;
        else ans = dp[k][n];
        printf("%lld\n", ans);
    }
    return (0-0); //<3
}