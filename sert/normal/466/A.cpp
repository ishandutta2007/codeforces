#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

long long n, m, a, b;

int main() {
    ///freopen("a.in", "r", stdin);
    cin >> n >> m >> a >> b;
    if (m * a <= b)
        cout << a * n;
    else
        cout << (n / m) * b + min(b, (n % m) * a);
    return 0;
}