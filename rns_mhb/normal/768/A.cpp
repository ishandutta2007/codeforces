#include <bits/stdc++.h>
using namespace std;

#define N 100000

int n, a[N], id[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", a + i);
    sort(a, a + n);
    int ress = 0, resd = n - 1;
    while (a[ress] == a[0]) ress ++;
    while (a[resd] == a[n - 1]) resd --;
    printf("%d", max(resd - ress + 1, 0));
}