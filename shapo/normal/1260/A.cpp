#include <bits/stdc++.h>

using namespace std;

int
main()
{
    int n, c, sum;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c >> sum;
        int p = sum / c, q = sum % c;
        // We have
        // * (c - q) numbers `p`
        // * q numbers `p + 1`
        int total_sum = (c - q) * p * p + q * (p + 1) * (p + 1);
        cout << total_sum << '\n';
    }
    return 0;
}