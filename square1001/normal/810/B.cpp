#include <bits/stdc++.h>
using namespace std;
int n, f, a[100009], b[100009], p[100009];
int main() {
    scanf("%d %d", &n, &f);
    long long ret = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        p[i] = min(a[i] * 2, b[i]) - min(a[i], b[i]);
        ret += min(a[i], b[i]);
    }
    sort(p, p + n, greater<int>());
    for(int i = 0; i < f; i++) ret += p[i];
    printf("%lld\n", ret);
    return 0;
}