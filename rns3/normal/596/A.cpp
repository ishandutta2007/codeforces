#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define M 100101
const int mod = 1000003;

void End() {
    puts("-1");
    exit(0);
}

int ABS(int u) {return u < 0 ? -u : u;}

int n;
int p[5];
int x[5], y[5];
int xx[5], yy[5];

void ok() {
    for (int i = 0; i < 4; i++) for (int j = i + 1; j < 4; j++) {
        if (y[i] > y[j] || (y[i] == y[j] && x[i] > x[j])) swap(x[i], x[j]), swap(y[i], y[j]);
    }

    if (y[0] != y[1] || y[2] != y[3] || x[0] != x[2] || x[1] != x[3]) return;
    if (y[0] == y[2] || x[0] == x[1]) return;
    printf("%d\n", (y[2] - y[0]) * (x[1] - x[0]));
    exit(0);
}

int main() {
   // freopen("A2.in", "r", stdin);
    scanf("%d", &n);
    if (n == 1) End();
    for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
    if (n == 2) {
        if (x[0] == x[1] || y[0] == y[1]) End();
        printf("%d\n", ABS(x[0]-x[1])*ABS(y[0]-y[1]));
        return 0;
    }

    for (int i = 0; i < n; i++) xx[i] = x[i], yy[i] = y[i];
    if (n == 4) {
        ok();
        End();
    }
    if (n == 3) {
        int tx = 0, ty = 0;
        for (int i = 0; i < 3; i++) tx += xx[i], ty += yy[i];
        for (int i = 0; i < 3; i++) {
            xx[3] = tx - 2 * xx[i], yy[3] = ty - 2 * yy[i];
            for (int j = 0; j < 4; j++) x[j] = xx[j], y[j] = yy[j];
            ok();
        }
        End();
    }
    return 0;
}