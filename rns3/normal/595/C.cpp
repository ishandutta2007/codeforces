#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
#define M 202020
const int mod = 1000000007;
typedef pair<int, int> pii;
#define x first
#define y second

int n;
int x[M];
int y[M];

bool ok(int len) {
    int gas = 0;
    for (int last = x[0], i = 1; i < n; i++) {
        if (x[i] <= last + len) gas++;
        else {
            last = x[i];
        }
    }
    printf("len = %d, gas = %d\n", len, gas);
    return gas <= n / 2;
}

int solve(int *x) {
    for (int i = 0; i < n; i++) printf("%d ", x[i]); puts("");
    int mn = 0, mx = x[n-1] - x[0];
    while (mn < mx - 1) {
        int mid = (mn + mx) / 2;
        if (ok(mid)) mn = mid;
        else mx = mid;
    }
    exit(0);
    return mn + 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", x + i);
    sort(x, x + n);
    int ans = x[n-1] - x[0];

    for (int i = 0; i < n / 2; i++) ans = min(ans, x[i + n/2] - x[i]);

    printf("%d\n", ans);
    return 0;
}