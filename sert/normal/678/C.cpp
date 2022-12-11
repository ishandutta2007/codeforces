#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5000 + 34;
typedef long double ld;

ll n, a, b, p, q;

int main() {
    cin >> n >> a >> b >> p >> q;
    cout << n / a * p + n / b * q - n / (a * b / __gcd(a, b)) * min(p, q);
    return 0;
}