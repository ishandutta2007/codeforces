#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, l[N], r[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d %d", &l[i], &r[i]);
    sort(l, l + n), sort(r, r + n);
    long long rlt = 0;
    for (int i = 0; i < n; i ++) rlt += max(l[i], r[i]) + 1;
    printf("%I64d\n", rlt);
}