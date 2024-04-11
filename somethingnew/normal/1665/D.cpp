#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
int X = 329329329;
int zpr(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    if (x % 3 == 0)
        x /= 3;
    return x;
}
void solve() {
    int num = 0;
    int pr = 1;
    for (int i = 0; i < 30; ++i) {
        int rs = zpr(pr * 3 - num, pr-num);
        //cout << rs << endl;
        if (rs == 2 * pr)
            num += pr;
        pr *= 2;
    }
    cout << "! " << num << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}