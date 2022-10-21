#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 100010;

int n, k, s[N], a[N];

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d%d", &n, &k);
        for (int i = n - k + 1; i <= n; i ++) scanf("%d", &s[i]);
        if (k == 1) {
            puts("YES");
            continue;
        }
        for (int i = n; i > n - k + 1; i --) a[i] = s[i] - s[i - 1];
        bool ok = 1;
        if (1ll * s[n - k + 1] <= 1ll * a[n - k + 2] * (n - k + 1)) ok = 1;
        else ok = 0;
        for (int i = n; i > n - k + 2 && ok; i --) {
            if(a[i] < a[i - 1]) ok = 0;
        }
        puts(ok ? "YES" : "NO");
    }

    return 0;
}