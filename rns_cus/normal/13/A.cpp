#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    int p = 0, q = a - 2;
    for (int b = 2; b < a; b ++) {
        int t = a;
        while (t) p += t % b, t /= b;
    }
    int d = __gcd(p, q);
    p /= d, q /= d;
    printf("%d/%d\n", p, q);

    return 0;
}