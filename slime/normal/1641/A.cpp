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
const int maxn = 200005;
int a[maxn];
int fl[maxn];
int fa[maxn]; 
int gfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = gfa(fa[x]);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n + 1; i++) fa[i] = i;
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) fl[i] = 0;
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            ll nd = 1ll * a[j] * x;
            if (fl[j]) continue;
            ans += 1;
            if (nd < 1e9) {
                int p = lower_bound(a + 1, a + n + 1, nd) - a;
                if (a[p] != nd) continue;
                else {
                    int nx = gfa(p);    
                    if (nx > n || a[nx] != nd) continue;
                    fl[nx] = 1, fa[nx] = nx + 1; ans -= 1;
                }
            }
        }
        printf("%d\n", ans);

    }
    return (0-0); //<3
}