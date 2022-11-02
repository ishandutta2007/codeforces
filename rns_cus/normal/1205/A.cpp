#include <bits/stdc++.h>
using namespace std;

#define N 200100

int a[N];

int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) puts("NO");
    else {
        puts("YES");
        for (int i = 1; i <= n; i ++) a[i] = (i & 1) ? 2 * i : 2 * i - 1;
        for (int i = 1; i <= n; i ++) a[i+n] = 4 * i - 1 - a[i];
        for (int i = 1; i <= 2 * n; i ++) printf("%d ", a[i]);
    }

    return 0;
}