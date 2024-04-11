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
int t;
int main() {
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> r(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &r[i]);
            while (r[i] % 2 == 0) r[i] /= 2, cnt += 1;
        }
        sort(r.begin(), r.end());
        r[n - 1] *= (1ll << cnt);
        ll ans = 0;
        for (int i = 0; i < n; i++) ans += r[i];
        cout << ans << endl;
    }
    return (0-0); //<3
}