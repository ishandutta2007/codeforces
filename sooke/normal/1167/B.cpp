#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

inline int query(int x, int y) {
    std::cout << "? " << x << " " << y << std::endl;
    int res; std::cin >> res; return res;
}

int a, b, c, d, a1, a2, a3, a4, a5, a6;

int main() {
    a = query(1, 2);
    b = query(1, 3);
    c = query(1, 4);
    d = query(1, 5);
    a1 = gcd(gcd(gcd(a, b), c), d);
    a1 = a1 == 30 ? 15 : a1 == 46 ? 23 : a1;
    a2 = a / a1;
    a3 = b / a1;
    a4 = c / a1;
    a5 = d / a1;
    a6 = 7418880 / a1 / a2 / a3 / a4 / a5;
    std::cout << "! " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << std::endl;
    return 0;
}