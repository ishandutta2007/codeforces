#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 3;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;
    a += 1000000000;
    b += 1000000000;
    if ((a < b && c < 0) || (a > b && c > 0)) {
        cout << "NO\n";
        return 0;
    }
    if (c == 0)
        cout << (a == b ? "YES" : "NO");
    else
        cout << (a % c == b % c ? "YES" : "NO");

    return 0;
}