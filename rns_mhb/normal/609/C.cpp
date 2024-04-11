#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n;
int a[N], b[N];
int sum, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n, greater<int>());
    int tmp = sum / n;
    sum %= n;
    for (int i = 0; i < n; i ++) {
        b[i] = tmp;
        if (i < sum) b[i] ++;
    }
    for (int i = 0; i < n; i ++) {
        if (a[i] > b[i]) ans += a[i] - b[i];
    }
    printf("%d\n", ans);
    return 0;
}