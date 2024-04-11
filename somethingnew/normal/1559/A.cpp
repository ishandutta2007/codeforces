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
#define all(x) (x).begin(), (x).end()

using namespace std;
void solve() {
    int n;
    cin >> n;
    int res = 1;
    cin >> res;
    for (int i = 0; i < n - 1; ++i) {
        int x;
        cin >> x;
        res &= x;
    }
    cout << res << '\n';
}
signed main() {
    int n;
    cin >> n;
    while (n--) solve();
}