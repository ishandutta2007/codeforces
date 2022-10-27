#include <iostream>
#include <vector>
using namespace std;

/*
2*d 3*d/2*t

*/
typedef long long LL;
long long k, d, t;
int main() {
    cin >> k >> d >> t;
    
    LL T = k - k % d + d;
    if (k % d == 0) T -= d;

    LL T1 = k, T2 = T - k; // 2, 1
    LL s = 2L*T1 + T2;
    LL tot = 2*t;

    double ans = (tot / s) * (double)T;
    tot %= s;
    if (tot <= 2L*T1) {
        ans += tot / 2.0;
    } else {
        ans += T1 + (tot - 2L*T1);
    }
    printf("%.12f\n", ans);
}