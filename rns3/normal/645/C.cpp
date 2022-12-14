#include <bits/stdc++.h>
using namespace std;
#define M 100100
typedef long long ll;

char s[M];

int n, m;
int cnt[M];

int calc(int a, int b) {
    return cnt[b] - cnt[a - 1];
}

bool ok(int dis) {
    for (int i = 1; i <= n; i++) if (s[i] == '0') {
        int cnt = calc(max(1, i - dis), min(n, i + dis));
        if (cnt >= m + 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ///freopen("C3.in", "r", stdin);
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i-1] + (s[i] == '0');
    }
    int mn = 0, mx = n;

    while (mn < mx - 1) {
        int mid = (mn + mx) / 2;
        if (ok(mid)) {
            mx = mid;
        } else {
            mn = mid;
        }
    }
    printf("%d\n", mx);
    return 0;
}