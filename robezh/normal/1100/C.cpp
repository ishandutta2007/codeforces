#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld EPS = (ld)1e-8, PI = 3.1415926535;

int n, r;

bool check(ld R) {
    ld s = asin(R / (R + r));
    return s * 2 * n <= 2 * PI;
}

int main() {
    cin >> n >> r;
    ld l = 0, r = 10000000, mid;
    while(l + EPS < r) {
        mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(10) << r << endl;
}