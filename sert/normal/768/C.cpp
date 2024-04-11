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

int n, x, k, a[N], b[N];

int main() {
    init();
    int y;
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &y);
        a[y]++;
    }

    int num, big, smal;
    for (int iq = 0; iq < k; iq++) {
        for (int i = 0; i < 1024; i++)
            b[i] = 0;
        num = 0;
        for (int i = 0; i < 1024; i++) {
            smal = a[i] / 2;
            big = a[i] - smal;
            if (num % 2 == 0) {
                b[i ^ x] += big;
                b[i] += smal;
            } else {
                b[i ^ x] += smal;
                b[i] += big;
            }
            num += a[i];
        }
        for (int i = 0; i < 1024; i++) {
            a[i] = b[i];
        }
    }

    int mx = -1;
    int mn = -1;
    for (int i = 0; i < 1024; i++) {
        if (a[i]) {
            if (mn == -1) mn = i;
            mx = i;
        }
    }

    printf("%d %d\n", mx, mn);

    return 0;
}