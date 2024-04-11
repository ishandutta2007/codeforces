#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int d = __gcd(1ll*n*m, 1ll * k);
    if(k == 1 || k / d > 2) {puts("NO"); return 0;}
    long long v = 2ll * n * m / k;
    if(k % 2 == 0) m = 2 * m / __gcd(2 * m, k);
    else if(__gcd(m, k) > 1) m = 2 * m / __gcd(m, k);
    printf("YES\n0 0\n%d 0\n0 %d\n", int(v / m), m);
}