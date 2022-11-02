#include <bits/stdc++.h>
using namespace std;

#define N 10000

typedef long long ll;
ll f[N];
ll n;

int main() {
    scanf("%I64d", &n);
    f[1] = 2, f[2] = 3;
    for (int i = 3; i < 1000; i ++) f[i] = f[i-1] + f[i-2];
    int ans = 1;
    while (f[ans] <= n) ans ++;
    printf("%d\n", ans - 1);
}