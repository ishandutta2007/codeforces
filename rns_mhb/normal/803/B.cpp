#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n;
int a[N], l[N], r[N];

int main() {
    scanf("%d", &n);
    l[0] = n;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (a[i]) l[i] = l[i-1] + 1;
        else l[i] = 0;
    }
    r[n+1] = n;
    for (int i = n; i; i --) {
        if (a[i]) r[i] = r[i+1] + 1;
        else r[i] = 0;
    }
    for (int i = 1; i <= n; i ++) printf("%d ", min(l[i], r[i]));
    return 0;
}