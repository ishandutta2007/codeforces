#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int x, y;
    cin >> x >> y;
    if (x == 0 and y == 0) {
        cout << "0\n";
        return;
    }
    int vl = sqrt(x * x + y * y);
    while (vl * vl < x * x + y * y)
        vl++;
    while (vl * vl > x * x + y * y)
        vl--;
    if (vl * vl != x * x + y * y)
        cout << "2\n";
    else
        cout << "1\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}