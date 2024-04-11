#include <iostream>

int a, b, c, d, e, f;

int main() {
    std::cin >> a >> b >> c >> d >> e >> f;
    for (b; b; b--) {
        a += b;
        if (b == d) { a -= c; }
        if (b == f) { a -= e; }
        if (a <= 0) { a = 0; }
    }
    std::cout << a << std::endl;
    return 0;
}