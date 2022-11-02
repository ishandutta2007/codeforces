#include <bits/stdc++.h>
using namespace std;

#define N 505

template<class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
typedef long long ll;
const ll INF = 1e18;
int n, rt;
int a[N];
ll ans;

int f(int a, int x) {
    if (!x) return a;
    if (a / x >= (a % x)) {
        return (a + x) / (x + 1);
    }
    else return 0;
}

ll calc(int x) {
    if (x < 0) return INF;
    ll rtn = 0;
    for (int i = 0; i < n; i ++) {
        int tmp = f(a[i], x);
        if (!tmp) return INF;
        rtn += tmp;
    }
    return rtn;
}

int main() {
    ans = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    rt = sqrt(a[0]);
    for (int i = 1; i <= rt + 2; i ++) {
        chkmin(ans, calc(i));
    }
    for (int i = 1; i <= rt + 2; i ++) {
        chkmin(ans, calc(a[0] / i));
        chkmin(ans, calc(a[0] / i - 1));
    }
    printf("%I64d\n", ans);
    return 0;
}