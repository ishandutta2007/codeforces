#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c  >> d;

    int g = __gcd(c, d);
    c /= g;
    d /= g;

    if(a * d < b * c) {
//        b / (a / c * d) = b * c / (a * d)
        int x = b * c;
        int y = a * d;
        int g = __gcd(x, y);

        x /= g;
        y /= g;

        cout << (x - y) << '/' << x;
    } else {
        int x = b * c;
        int y = a * d;
//        cout << x << ' ' << y << endl;
        int g = __gcd(x, y);

         x /= g;
         y /= g;

//         cout << x << ' ' << y << endl;

        cout << (y - x) << '/' << y;
    }

    /*int i = 0;
    for(; c * i <= a && d * i <= b; i++);

    c *= i - 1;
    d *= i - 1;

    int x = c * d;
    int y = a * b;

    g = __gcd(x, y);

    cout << x / g << '/' << y / g << endl;*/


}