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

int n, m, k, p = 1, x, a, b;
bool u[N];

int main() {
    init();

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        u[x] = true;
    }
    while (k--) {
        if (u[p]) {
            printf("%d\n", p);
            return 0;
        }
        scanf("%d%d", &a, &b);
        if (p == a || p == b)
            p = a + b - p;
    }
    printf("%d\n", p);
    return 0;
}