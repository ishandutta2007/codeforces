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
#include "queue"

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    ll a, b;
    cin >> a >> b;
    if ((a * b + a) % (a * b) == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << a * b << ' ' << a << ' ' << a * b + a << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}