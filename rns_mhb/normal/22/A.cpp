#include <bits/stdc++.h>
using namespace std;

#define N 105

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", a + i);
    sort(a, a + n);
    if (a[0] == a[n-1]) puts("NO");
    else {
        int p = 1;
        while (a[p] == a[0]) p ++;
        printf("%d\n", a[p]);
    }
}