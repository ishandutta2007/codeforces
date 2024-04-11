#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, x;
    scanf("%d", &t);
    while(t --) {
        scanf("%d", &x);
        int n = 180;
        int d = __gcd(x, n);
        x /= d, n /= d;
        if(x + 1 == n) n *= 2;
        printf("%d\n", n);
    }
}