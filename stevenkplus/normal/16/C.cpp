#include <iostream>
#include <algorithm>

using namespace std;

int a,b,x,y;

int main() {
    cin >> a >> b >> x >> y;
    int g = __gcd(x, y);
    x /= g;
    y /= g;
    int k = min(a / x, b / y);
    cout << k * x << " " << k * y << endl;
    return 0;
}