#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long mi = min({a + b, a + c, d + b, d + c}), ma = max({a + b, a + c, d + b, d + c});
    long long  dif = ma - mi;
    cout << n * max(0ll, n - dif) << endl;
}