#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 105
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int a[maxn], b[maxn];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b[x] = 1;
    }
    vector<pi> cur;
    for (int i = 1; i <= n; i++)
        cur.pb(mp(a[i], i));
    sort(cur.begin(), cur.end());
    reverse(cur.begin(), cur.end());
    ll ans = 0;
    for (auto v : cur) {
        int id = v.se;
        if (b[id]) continue;
        ans += a[id];
    }
    for (auto v : cur) {
        int id = v.se;
        if (b[id]) {
            ll cr = max(ans, (ll)a[id]);
            ans += cr;
        }
    }
    cout << ans << endl;

    return 0;
}