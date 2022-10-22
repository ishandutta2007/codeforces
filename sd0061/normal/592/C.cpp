#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef long long LL;

int main() {
    LL t, w, b, g, q, r, x, a;
    cin >> t >> w >> b;
    g = __gcd(w, b);
    q = (t + 1) / w / (b / g);
    r = (t + 1) - q * w * (b / g);
    x = min(w, b);
    a = x * q + min(x, r) - 1;
    g = __gcd(a, t);
    cout << a / g << '/' << t / g << endl;
    return 0;
}