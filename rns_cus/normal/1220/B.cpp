#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, a[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i ++) {
        int j, k;
        if (i > 1) j = 0, k = 1;
        else if (i == 1) j = 0, k = 2;
        else j = 1, k = 2;
        long long m = 1ll * a[i][j] * a[i][k];
        printf("%d ", (int)sqrt(1.0 * m / a[j][k]));
    }

    return 0;
}