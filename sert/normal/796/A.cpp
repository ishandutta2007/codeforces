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

const int N = (int)1e6 + 34;

int a[N], n, m, k, d;

int main() {
    init();

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    d = n;
    for (int i = 0; i < n; i++)
        if (a[i] && a[i] <= k && abs(i + 1 - m) < d)
            d = abs(i + 1 - m);
    printf("%d\n", d * 10);
    return 0;
}