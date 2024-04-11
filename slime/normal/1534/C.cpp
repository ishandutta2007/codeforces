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
const int maxn = 400005;
int p[maxn];
int a[2][maxn];
int vis[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int j = 0; j < 2; j++)
            for (int i = 1; i <= n; i++) 
                scanf("%d", &a[j][i]);
        for (int i = 1; i <= n; i++)
            p[a[0][i]] = a[1][i];
        ll ans = 1;
        for (int i = 1; i <= n; i++) vis[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            ans = ans * 2 % mod;
            int x = i;
            while (1) {
                vis[x] = 1;
                x = p[x];
                if (x == i) break;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}