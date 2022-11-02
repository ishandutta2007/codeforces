#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    scanf("%d", &n);
    k = n / 2;
    if (n & 1) {
        for (int i = 0; i < k; i ++) printf("%d ", 2 * i + 1);
        printf("%d ", 2 * k + 1);
        for (int i = k - 1; i >= 0; i --) printf("%d ", 2 * i + 1);
        printf("%d ", 2 * k + 1);
        for (int i = 1; i <= k; i ++) printf("%d ", 2 * i);
        for (int i = k; i >= 1; i --) printf("%d ", 2 * i);
    }
    else {
        for (int i = 0; i < k; i ++) printf("%d ", 2 * i + 1);
        for (int i = k - 1; i >= 0; i --) printf("%d ", 2 * i + 1);
        printf("%d ", 2 * k);
        for (int i = 1; i <= k; i ++) printf("%d ", 2 * i);
        for (int i = k - 1; i >= 1; i --) printf("%d ", 2 * i);
    }
    return 0;
}