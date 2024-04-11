#include <bits/stdc++.h>

using namespace std;


int n, m, a, b;

int run() {
    if(m == 1) return 1;
    if(a % m == 1) {
        if(b - a <= m - 1 || b % m == 0 || b == n) return 1;
        return 2;
    }
    if((a - 1) / m == (b - 1) / m) return 1;
    if((a - 1) / m + 1 == (b - 1) / m) return 2;
    if(b % m == 0 || b == n) return 2;
    if((b + 1) % m == a % m) return 2;
    return 3;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &a, &b);
    printf("%d\n", run());
    return 0;
}