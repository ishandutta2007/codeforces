#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld EPS = 1e-10;
const ld INF = 10000;
const int N = 10000;

void ret(int x) {
    cout << x;
    exit(0);
}

int main() {
    int n, m, a, b, r1, r2, c1, c2;
    cin >> n >> m >> a >> b;

    if (b == n) {
        b += m - 1;
        b -= b % m;
    }

    a--;
    b--;
    r1 = a / m;
    r2 = b / m;
    c1 = a % m;
    c2 = b % m;

    if (r1 == r2)
        ret(1);
    if (c1 == 0 && c2 == m - 1)
        ret(1);
    if (r1 + 1 == r2)
        ret(2);
    if (c1 == 0 || c2 == m - 1)
        ret(2);
    if (c1 - 1 == c2)
        ret(2);
    ret(3);

    return 0;
}