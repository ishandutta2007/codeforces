#include <bits/stdc++.h>
using namespace std;

int n, res, x;

int main() {
    scanf("%d", &n);
    res = (n * n) / 4;
    printf("%d\n", res);
    x = n / 2;
    for(int i = 1; i <= x; i ++) {
        for(int j = x + 1; j <= n; j ++) printf("%d %d\n", i, j);
    }
}