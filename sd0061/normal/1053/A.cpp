#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, K, g = 1;
    cin >> n >> m >> K;
    if (2LL * n * m % K == 0) {
        puts("YES");
        if (K % 2 == 0) {
            K /= 2;
        } else {
            g = 2;
        }
        // K | nm
        int d = __gcd(K , n);
        int x = n / d;
        int y = m / (K / d);
        if (x * g <= n) {
            x *= g;
        } else {
            y *= g;
        }
        printf("0 0\n%d 0\n0 %d\n" , x , y); 
    } else {
        puts("NO");
    }


}