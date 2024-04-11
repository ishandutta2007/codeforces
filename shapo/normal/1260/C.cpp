#include <bits/stdc++.h>

using namespace std;

int
gcd(int a, int b)
{
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int
main()
{
    int t, r, b, k;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        cin >> r >> b >> k;
        if (r > b) {
            swap(r, b);
        }
        // Now assume that r <= b
        int g = gcd(r, b);
        if (((b - g) + r - 1) / r >= k) {
            cout << "REBEL\n";
        } else {
            cout << "OBEY\n";
        }
    }
    return 0;
}