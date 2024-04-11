#include <bits/stdc++.h>
using namespace std;

#define N 105
typedef long long ll;

int n;
int p[N];
bool vis[N];
ll ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i ++)
    for (int j = i + 1; j <= n; j ++) {
        if (p[i] == p[j]) {
            printf("-1\n");
            return 0;
        }
    }
    ans = 1;
    for (int i = 1; i <= n; i ++) if (!vis[i]) {
        vis[i] = 1;
        if (p[i] == i) continue;
        int now = p[i], sz = 1;
        while (now != i) {
            sz ++;
            now = p[now];
            vis[now] = 1;
        }
        if (sz & 1) {
            ans = ans * sz / __gcd(ans, (ll)sz);
        }
        else {
            sz /= 2;
            ans = ans * sz / __gcd(ans, (ll)sz);
        }
    }
    printf("%I64d\n", ans);
}