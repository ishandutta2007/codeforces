#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long l, r, x, y;
    cin >> l >> r >> x >> y;

    long long product = x * y, ret = 0;
    for (long long a=1; a*a<=y; a++) {
        if (y % a == 0) {
            if (l <= a && a <= r) {
                long long b = product / a;
                if (l <= b && b <= r) {
                    long long g = __gcd(a, b);
                    if (g == x && product / g == y) {
                        ret++;
                        //cout << a << ", " << b << "\n";
                    }
                }
            }
            if (a != y / a && l <= y / a && y / a <= r) {
                a = y / a;
                long long b = product / a;
                if (l <= b && b <= r) {
                    long long g = __gcd(a, b);
                    if (g == x && product / g == y) {
                        ret++;
                        //cout << a << ", " << b << "\n";
                    }
                }
                a = y / a;
            }
        }
    }

    cout << ret << "\n";

    return 0;
}