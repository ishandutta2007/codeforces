#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 100010;

int n, a[N], vis[2];

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d", &n);
        vis[0] = vis[1] = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            if (a[i] < 2) vis[a[i]] = 1;
        }
        sort(a + 1, a + n + 1);
        if (!vis[1]) {
            puts("YES");
            continue;
        }
        if (vis[0]) {
            puts("NO");
            continue;
        }
        bool ok = 1;
        for (int i = 1; i < n && ok; i ++) {
            if (a[i] + 1 == a[i + 1]) {
                puts("NO");
                ok = 0;
            }
        }
        if (ok) puts("YES");
    }
    return 0;
}