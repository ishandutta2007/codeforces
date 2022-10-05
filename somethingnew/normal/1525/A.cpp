#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "array"
#include "queue"
#include "map"
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int a;
    cin >> a;
    int t = __gcd(a, 100);
    cout << 100 / t << '\n';
}
signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}