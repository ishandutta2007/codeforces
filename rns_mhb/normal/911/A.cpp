#include <bits/stdc++.h>
using namespace std;

#define N 100005
int a[N];

int main() {
    int n;
    scanf("%d", &n);
    int mn = 1e9 + 7, ans = N, prv = -N;
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), mn = min(mn, a[i]);
    for (int i = 1; i <= n; i ++) if (a[i] == mn) {
        ans = min(ans, i - prv);
        prv = i;
    }
    printf("%d\n", ans);
}