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
const int maxn = 2005;
int n, m;
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<ll> cur;
        for (int i = 1; i <= n; i++) {
            ll sum = 0;
            for (int j = 1; j <= m; j++) {
                ll x;
                cin >> x;
                sum += 1ll * j * x;
            }
            cur.pb(sum);
        }
        ll res = cur[0];
        if (cur[0] != cur[n - 1]) res = cur[1];
        for (int i = 0; i < n; i++) {
            if (cur[i] != res) {
                printf("%d %lld\n", i + 1, cur[i] - res);
            }
        }
    }
    return (0-0); //<3
}
/*
6
4 5 2 6 1 3
*/