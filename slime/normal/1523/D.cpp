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
int n, m, p;
const int maxn = 200005;
ll a[maxn];
char inp[65];
mt19937 cur(123);
int cnt[1 << 15];
int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        scanf("%s", inp);
        a[i] = 0;
        for (int j = 0; j < m; j++)
            if (inp[j] == '1') a[i] += (1ll << j);
    }
    int mx = 0;
    ll res = 0;
    for (int k = 1; k <= 20; k++) {
        ll rd = cur() % n + 1;
        vi cr;
        for (int j = 0; j < m; j++)
            if (a[rd] & (1ll << j)) cr.pb(j);
        int l = cr.size();
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= n; j++) {
            ll e = a[j] & a[rd];
            int f = 0;
            for (int s = 0; s < l; s++)
                if (e & (1ll << cr[s])) f ^= (1 << s);
            cnt[f]++;
        }
        for (int j = 0; j < l; j++)
            for (int k = 0; k < (1 << l); k++)
                if (k & (1 << j))
                    cnt[k ^ (1 << j)] += cnt[k];
        int nmx = 0;
        ll np = 0;
        for (int k = 0; k < (1 << l); k++)
            if (cnt[k] >= (n + 1) / 2)
                if (chkmax(nmx, __builtin_popcount(k))) np = k;
        ll cs = 0;
        for (int k = 0; k < l; k++)
            if (np & (1 << k)) cs ^= (1ll << cr[k]);
        if (chkmax(mx, nmx)) res = cs;
    }
    for (int i = 0; i < m; i++)
        if (res & (1ll << i)) cout << '1';
        else cout << '0';
    return 0;
}