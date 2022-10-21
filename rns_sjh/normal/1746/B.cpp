#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 200500;
const int inf = 1e9 + 50;
const int mod = 998244353;

int n, a[N];

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d", &n);
        int x = 0, y = 0;
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), x += a[i];
        int ans = n;
        for (int i = n; i >= 0; i --) if(x >= y) {
            ans = min(ans, x);
            x -= a[i];
            y += 1 - a[i];
        }
        printf("%d\n", ans);
    }

    return 0;
}