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

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

void solve() {
    ll n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<bool> inc(n, false);
    inc[n - 1] = true;
    vector<int> b;
    b.push_back(a.back());
    int cgcd = a.back();
    for (int it = 0; it < n - 1; ++it) {
        vector<pair<int, int>> lgc;
        for (int i = 0; i < n; ++i) {
            if (!inc[i]) {
                lgc.push_back({ gcd(cgcd, a[i]), i });
            }
        }
        sort(lgc.begin(), lgc.end());
        inc[lgc.back().second] = true;
        b.push_back(a[lgc.back().second]);
        cgcd = lgc.back().first;
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";
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