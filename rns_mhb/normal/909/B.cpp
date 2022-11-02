#include <bits/stdc++.h>
using namespace std;


int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int n, k;
    scanf("%d", &n);
    k = n / 2;
    if (n & 1) n = (k + 1) * (k + 1);
    else n = k * (k + 1);
    printf("%d\n", n);
    return 0;
}