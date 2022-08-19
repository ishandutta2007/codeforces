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
const int maxn = 1005;
int x[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i += 2) {
        ll sum = 0, lb = 0;
        for (int j = i + 1; j <= n; j++) {
            if (j % 2 == 0) {
                ll dif = -sum;
                ll l = -lb;
                chkmax(l, 1ll);
                chkmax(l, 1 + dif);
                ll r = x[i];
                chkmin(r, x[j] + dif);
                if (r >= l) ans += r - l + 1;
            }
            if (j % 2) sum += x[j];
            else sum -= x[j];
            chkmin(lb, sum);
            if (j % 2) continue;
        }
    }
    cout << ans << endl;
    return (0-0); //<3
}