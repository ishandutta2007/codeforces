#include <bits/stdc++.h>
using namespace std;

#define N 500005

template<class T> void chkmax(T &a, T b) { if (a < b) a = b; }
typedef long long ll;

ll ans;
int n;
int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d ", &a[i]);
    for (int i = 1; i <= n; i ++) {
        char ch = getchar();
        if (ch == 'B') a[i] = -a[i];
    }
    ll now = 0;
    for (int i = 1; i <= n; i ++) {
        now += a[i];
        chkmax(ans, now);
    }
    now = 0;
    for (int i = n; i >= 1; i --) {
        now += a[i];
        chkmax(ans, now);
    }
    for (int i = 1; i <= n; i ++) {
        if (a[i] < 0) ans -= a[i];
    }
    printf("%I64d\n", ans);
    return 0;
}