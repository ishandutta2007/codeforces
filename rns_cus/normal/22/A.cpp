#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    sort(a, a + n);
    n = unique(a, a + n) - a;
    if (n == 1) puts("NO");
    else printf("%d\n", a[1]);
    
}