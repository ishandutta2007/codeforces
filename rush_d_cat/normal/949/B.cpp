#include <iostream>
using namespace std;
typedef long long LL;
LL n, q;
LL x;

int main() {
    scanf("%lld %lld", &n, &q);
    
    while (q --) {
        scanf("%lld", &x);
        if (x % 2 == 1) {
            printf("%lld\n", (x+1) / 2);
        } else {
            LL d = n - x/2;
            LL cur = x;
            //printf("%lld %lld\n", d, cur);
            while (d + cur <= 2*n-2 && d >= 2) {
                cur += d;
                if (d%2 == 1) break;
                d = d / 2;
            }
            
            if (cur == 2*n - 2)
            {
                printf("%lld\n", n);
            } else {
                printf("%lld\n", (cur+1)/2);
            }

        }
    }
}