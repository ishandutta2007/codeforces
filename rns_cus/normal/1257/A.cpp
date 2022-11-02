#include <bits/stdc++.h>
using namespace std;

#define N 100100

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, x, a, b;
        scanf("%d %d %d %d", &n, &x, &a, &b);
        printf("%d\n", min(n - 1, abs(a - b) + x));
    }

    return 0;
}