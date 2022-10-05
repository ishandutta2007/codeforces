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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    vector<int> b = a;
    sort(all(b));
    int q = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i])
            q = 0;
    }
    if (q) {
        cout << "0\n";
        return;
    }
    if (a[0] == 1 or a.back() == n)
        cout << "1\n";
    else if (a[0] == n and a.back() == 1)
        cout << "3\n";
    else
        cout << "2\n";
}
signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}