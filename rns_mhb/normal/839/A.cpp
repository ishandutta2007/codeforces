#include <bits/stdc++.h>
using namespace std;

#define N 105

int n, k, now, cur;
int a[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        now += a[i];
        int d = min(now, 8);
        cur += d;
        now -= d;
        if (cur >= k) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}