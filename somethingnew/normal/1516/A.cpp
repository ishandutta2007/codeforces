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
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int kk = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
        int v = min(a[i], k - kk);
        kk += v;
        a[i] -= v;
    }
    cin >> a.back();
    a.back() += kk;
    for (auto i : a) {
        cout << i << ' ';
    }
    cout << endl;
}
signed main() {
    int n;
    cin >> n;
    while (n--) solve();
}