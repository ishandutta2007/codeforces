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
int n, m;
int a[maxn][6], w[maxn];
int cnt = 0;
map<int, ll> hs;
pair<ll, int> s[maxn * 32];
vector<vi> h[2];
bool chk(int a) {
    ll tot = 0;
    for (int i = 0; i < 2; i++) {
        ll ans = 0;
        for (auto &v: h[i]) {
            int p = v.size() - 1;
            for (int j = 0; j < v.size(); j++) {
                while (p >= 0 && v[p] + v[j] > a) p -= 1;
                if (p <= j) break;
                ans += p - j;
            }
        }
        if (i == 0) tot += ans;
        else tot -= ans;
    }
    return tot > 0;
}
mt19937 x;
const int pw = (1 << 30);
ll rd() {
    return x() & (pw - 1);
}
ll lrd() {
    return (((rd() << 30) | rd()) << 1) | 1;
}
ll ghs(int a) {
    if (hs[a]) return hs[a];
    hs[a] = lrd(); return hs[a];
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
        ll h[6];
        for (int j = 0; j < m; j++)
            h[j] = ghs(a[i][j]);
        scanf("%d", &w[i]);
        for (int j = 0; j < (1 << m); j++) {
            ll cr = 0;
            for (int k = 0; k < m; k++)
                if (j & (1 << k)) cr ^= h[k];
            s[cnt++] = mp(cr, w[i]);
        }
    }
    for (int i = 0; i < 2; i++)
        h[i].reserve(n * (1 << (m - 1)));
    sort(s, s + cnt);
    for (int i = 0; i < cnt; ) {
        int j = i;
        while (j < cnt && s[j].fi == s[i].fi) j += 1;
        vi cur(j - i);
        for (int k = i; k < j; k++) cur[k - i] = (s[k].se);
        h[(s[i].fi % 2)].pb(cur);
        i = j;
    }
  ll l = 0, r = 2e9 + 7;
    if (!chk(r)) cout << -1 << endl;
    else {
        while (l < r) {
            int mid = (l + r) >> 1;
            if (chk(mid)) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }

    return (0-0); //<3
}