#include <iostream>
#include <algorithm>

using namespace std;

int
gcd(int a, int b)
{
    while (b) {
        a %= b;
        swap(b, a);
    }
    return a;
}

int
main()
{
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    int ans = 0;
    if (y % x == 0) {
        int k = y / x;
        l = (l + x - 1) / x;
        r /= x;
        for (int i = 1; i * i <= k; ++i) {
            if (k % i == 0 && gcd(i, k / i) == 1) {
                int a = i, b = k / i;
                if (l <= a && a <= r && l <= b && b <= r) {
                    ans++;
                    if (a != b) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}