#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include "fstream"
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"

#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x, y, gc;
    gc = 1;
    for (int i = 0; i < c - 1; ++i) {
        gc *= 10;
    }
    x = y = gc;
    while (to_string(x).size() != a) {
        x *= 3;
    }
    while (to_string(y).size() != b) {
        y *= 7;
    }
    cout << x << ' ' << y << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}