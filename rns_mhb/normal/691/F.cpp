#include <bits/stdc++.h>
using namespace std;

#define N 3000005

typedef long long ll;

int n, q;
int a[N];
ll z[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        a[x] ++;
    }
    for (int i = 1; i < N; i ++)
    for (int j = 1; j * i < N; j ++) {
        z[i*j] += 1ll * a[i] * (a[j] - (i == j));
    }
    for (int i = 1; i < N; i ++) z[i] += z[i-1];
    scanf("%d", &q);
    while (q --) {
        int x;
        scanf("%d", &x);
        printf("%I64d\n", 1ll * n * (n - 1) - z[x-1]);
    }
    return 0;
}