#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100002;
LL p, k;
LL cof[N], deg[N];

int main() {
    cin >> p >> k;
    LL cp = p; int t = 0;
    while (cp) {
        cof[t ++] = cp % k;
        cp /= k;
    }

    for (int tt = 1; tt <= 10000; tt ++) {
        for (int i = 0; i <= 100; i ++) {
            if (i % 2 == 0) {
                while (cof[i] < 0) cof[i] += k, cof[i+1] --;
                while (cof[i] >= k) cof[i] -= k, cof[i+1] ++;
            }

            if (i % 2 == 1) {
                while (cof[i] > 0) cof[i] -= k, cof[i+1] ++;
                while (cof[i] <= -k) cof[i] += k, cof[i+1] --;
            }
        }
    }
    int lim = 100;
    for (lim = 100; lim >= 0 && cof[lim] == 0; lim --);

    printf("%d\n", lim+1);
    for (int i = 0; i < lim+1; i ++) {
        if (i % 2 == 1) cof[i] = - cof[i];
        printf("%lld ", cof[i]);
    }
    printf("\n");
}