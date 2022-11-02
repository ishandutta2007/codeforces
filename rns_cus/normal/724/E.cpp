#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 100001;
ll p[M], s[M];

ll f[M], g[M];

int main() {
    ///freopen("e.in", "r", stdin);
    int n;
    ll c;
    scanf("%d %I64d", &n, &c);
    for(int i = 0; i < n; i ++) scanf("%I64d", &p[i]);
    for(int i = 0; i < n; i ++) scanf("%I64d", &s[i]);
    for(int i = 0; i <= n; i ++) f[i] = (1ll << 60);
    f[0] = p[0];
    f[1] = s[0];
    for(int i = 1; i < n; i ++) {
        for(int j = 0; j <= n; j ++) g[j] = (1ll << 60);
        for(int j = 0; j <= i; j ++) {
            ///g[j] = f[j] + p[i] + s[i];
        }
        for(int j = 1; j <= i + 1; j ++) {
            g[j] = min(g[j], f[j-1] + s[i]);
        }
        for(int j = 0; j <= i; j ++) {
            g[j] = min(g[j], f[j] + 1ll * j * c + p[i]);
        }
        for(int j = 0; j <= n; j ++) f[j] = g[j];
    }
    ll ans = (1ll << 60);
    for(int i = 0; i <= n; i ++) ans = min(ans, f[i]);
    cout << ans << endl;
}