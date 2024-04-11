#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <random>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000007;

void solve() {
    ll n;
    cin >> n;
    vector<int> c({0, 0});
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++c[a];
    }
    if (c[0] >= c[1]) {
        cout << c[0] << "\n";
        for (int i = 0; i < c[0]; ++i) {
            cout << "0 ";
        }
        cout << "\n";
    }
    else {
        c[1] = c[1] / 2 * 2;
        cout << c[1] << "\n";
        for (int i = 0; i < c[1]; ++i) {
            cout << "1 ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}