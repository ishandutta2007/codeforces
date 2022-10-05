#include "list"
#include <iostream>
#include "queue"
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
int val(int x) {
    int res = x;
    for (int i = 10; i <= x; i *= 10) {
        res += x / i;
    }
    return res;
}
void solve() {
    int l, r;
    cin >> l >> r;
    cout << val(r) - val(l) << '\n';
}
signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}