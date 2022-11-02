#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, d, e;

int main() {
    scanf("%d %d %d", &n, &d, &e);
    e *= 5;
    int rlt = 1e9;
    for (int i = 0; i <= n; i += e) {
        rlt = min(rlt, (n - i) % d);
    }
    printf("%d\n", rlt);

    return 0;
}