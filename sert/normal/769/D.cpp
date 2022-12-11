#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

int n, k, x, len;
int a[N], b[N];
ll ans, t;

int main() {
    init();

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[x]++;
    }

    if (k == 0) {
        for (int i = 0; i <= 10000; i++) {
            t = a[i];
            ans += (t * (t - 1)) / 2;
        }
        printf("%I64d\n", ans);
        return 0;
    }

    for (int i = 0; i < (1 << 14); i++)
        if (__builtin_popcount(i) == k)
            b[len++] = i;

    for (int i = 0; i <= 10000; i++) {
        if (a[i] == 0) continue;
        t = a[i];
        //cerr << i << "\n";
        for (int j = 0; j < len; j++) {
            x = (i ^ b[j]);
            //cerr << i << " " << x << "\n";
            if (x > i) {
                ans += t * a[x];
            }
        }
    }

    printf("%I64d\n", ans);
    return 0;
}