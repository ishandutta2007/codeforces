#include <bits/stdc++.h>
using namespace std;

#define N 222

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i ++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
        int j = i + 1;
        while (a[j] != a[i]) j ++;
        ans += j - i - 1;
        while (j > i) a[j--] = a[j];
    }
    printf("%d\n", ans);

    return 0;
}