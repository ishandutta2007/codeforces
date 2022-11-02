#include <bits/stdc++.h>
using namespace std;

int q, l, r;

int calc(int n) {
    int m = n >> 1;
    if (n & 1) return -m - 1;
    else return m;
}

int main() {
    scanf("%d", &q);
    while (q --) {
        scanf("%d %d", &l, &r);
        printf("%d\n", calc(r) - calc(l - 1));
    }
}