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
#define S 20
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = (1 << 18);
int a[maxn];
ll u, v; // u + vx
ll umx = -1e18;
void upd(ll c) {
    double h = 1.0 * c * v + u;
    if (h > 1e18) umx = 1e18;
    else if (h < -1e18) return ;
    chkmax(umx, c * v + u);
}
void add(int i, int j, int tp = 1) {
    v += tp * (a[i] + a[j]);
    u += 1ll * tp * a[i] * a[j];
}
void cal(ll l, ll r) {
    upd(l), upd(r);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        // all positive
        umx = -1e18;
        u = 0, v = 0;
        for (int i = 2; i <= n; i++)
            add(1, i);
        cal(-a[1], 1e18);
        u = 0, v = 0;
        for (int i = 1; i < n; i++)
            add(i, n);
        cal(-1e18, -a[n]);
        for (int i = 1; i < n; i++) {
            if (i == 1) {
                u = v = 0;
                for (int j = 1; j <= i; j++)
                    add(j, n);
                for (int j = i + 1; j < n; j++)
                    add(j, 1);
            }
            else {
                add(i, n);
                add(i, 1, -1);
            }
            cal(-a[i + 1], -a[i]);
        }
        if (umx > 5e17) printf("INF\n");
        else printf("%lld\n", umx);
    }
    return (0-0); //<3
}
/*
1
4
1 2 3 -4
*/