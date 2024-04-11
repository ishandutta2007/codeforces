#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

typedef long double real;

real m, r, q;
real z = sqrt(2.0L);

void f() {
    std::cout << q << std::endl;
}

int main()
{
    std::cin >> m >> r;

    for (real i = 1.0L; i <= m; i++) {
        q += 2.0L*r;
        if (1.0L < i) q += 2.0L*r + r*z;
        if (i < m) q += 2.0L*r + r*z;
        //f();
        real a, b;
        a = std::max(0.0L, i-2.0L);
        q += a*a*r + a*2.0L*z*r + a*r;
        b = std::max(0.0L, m-i-1.0L);
        q += b*b*r + b*2.0L*z*r + b*r;
        //f();
    }

    q /= m*m;

    std::cout << std::fixed << std::setprecision(8) << q << std::endl;
}