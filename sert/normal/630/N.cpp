#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
const ll md = 1e9 + 7;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    long double a, b, c, d;
    cin >> a >> b >> c;
    cout.precision(12);
    d = sqrtl(b * b - 4 * a * c);
    if (a > 0) {
        cout << fixed << (-b + d) / (2 * a) << "\n";
        cout << fixed << (-b - d) / (2 * a);
    } else {
        cout << fixed << (-b - d) / (2 * a) << "\n";
        cout << fixed << (-b + d) / (2 * a);   
    }

    return 0;
}