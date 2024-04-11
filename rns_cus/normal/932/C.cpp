#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int n, a, b;

int main() {
    scanf("%d %d %d", &n, &a, &b);
    int k;
    for (k = 0; k <= n / b; k ++) {
        if ((n - b * k) % a == 0) break;
    }
    if (k > n / b) puts("-1");
    else {
        for (int i = 0; i < k; i ++) {
            for (int j = 2; j <= b; j ++) printf("%d ", i * b + j);
            printf("%d ", i * b + 1);
        }
        for (int i = 0; i < (n - b * k) / a; i ++) {
            for (int j = 2; j <= a; j ++) printf("%d ", i * a + j + b * k);
            printf("%d ", i * a + 1 + b * k);
        }
    }
}