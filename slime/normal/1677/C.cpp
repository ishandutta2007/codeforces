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
int nx[maxn], vis[maxn];
int h[2][maxn];
int main() {    
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < 2; j++) 
            for (int i = 0; i < n; i++)
                scanf("%d", &h[j][i]);
        for (int i = 0; i < n; i++)
            nx[h[0][i]] = h[1][i];
        for (int i = 1; i <= n; i++)
            vis[i] = 0;
        ll ans = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            vi cur;
            int p = i;
            while (1) {
                if (vis[p]) break;
                vis[p] = 1;
                cur.pb(p);
                p = nx[p];
            }
            int v = cur.size();
            cnt += v / 2;
        }
        for (int i = n; i >= n - cnt + 1; i--)
            ans += i;
        for (int i = 1; i <= cnt; i++)
            ans -= i;
        ans *= 2;
        printf("%lld\n", ans);
    }
    return 0;
}