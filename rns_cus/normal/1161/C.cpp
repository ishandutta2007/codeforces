#include <bits/stdc++.h>
using namespace std;

#define N 55

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    sort(a, a + n);
    int k = 0;
    while (k < n && a[k] == a[0]) k ++;
    if (k > n / 2) puts("Bob");
    else puts("Alice");

    return 0;
}