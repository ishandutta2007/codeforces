#include <bits/stdc++.h>
using namespace std;
const int N = 5012;
long long n, a, b, c, f;
int main() {
    cin >> n >> a >> b >> c;
    if (a <= b - c || n < b) {
        cout << n / a;
        return 0;
    }
    f = (n - c) / (b - c);
    n -= f * (b - c);
    cout << f + n / a;
}