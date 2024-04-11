//
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
const int maxn = 200005;
ll a[maxn];
ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        if (n == 1) printf("1\n");
        else {
            vector<pair<ll, int> > cur;
            int ans = 1;
            for (int i = n; i >= 2; i--) {
                ll h = abs(a[i] - a[i - 1]);
                for (int i = 0; i < cur.size(); i++) {
                    cur[i].fi = gcd(cur[i].fi, h);
                    cur[i].se += 1;
                }
                cur.pb(mp(h, 2));
                vector<pair<ll, int> > nx;
                for (int i = 0; i < cur.size(); i++) {
                    if (cur[i].fi == 1) continue;
                    chkmax(ans, cur[i].se);
                    if (i == 0 || cur[i].fi != cur[i - 1].fi)
                        nx.pb(cur[i]);
                }
                cur = nx;
            }
            printf("%d\n", ans);
        }
    }
    return (0-0); //<3
}