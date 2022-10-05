#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#define int long long
using namespace std;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a == b and c % 2 == 0) or (c == b and a % 2 == 0) or (a == c and b % 2 == 0)) {
        cout << "YES\n";
        return;
    }
    if (a + b + c - 2 * max(a, max(b, c)) == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) solve();
}
//abacdcababb