#include <bits/stdc++.h>

using namespace std;

int main() {
    long long k2, k3, k5, k6, sum = 0;
    cin >> k2 >> k3 >> k5 >> k6;
    long long c1 = min({k2, k5, k6});
    sum += c1 * 256;
    k2 -= c1;
    long long c2 = min(k3, k2);
    sum += c2 * 32;
    cout << sum;
}