#include <bits/stdc++.h>
using namespace std;

#define N 100005

typedef long long ll;
int n;
int a[N];
ll tot, ans, now;
ll l[N], r[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        tot += a[i];
    }
    if (tot % 3) return puts("0"), 0;
    tot /= 3;
    for (int i = 1; i <= n; i ++) {
        now += a[i];
        l[i] = l[i-1] + (now == tot);
    }
    now = 0;
    for (int i = n; i >= 3; i --) {
        now += a[i];
        if (now == tot) {
            ans += l[i-2];
        }
    }
    printf("%I64d\n", ans);
    return 0;
}