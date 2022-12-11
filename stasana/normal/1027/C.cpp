#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int_fast64_t ll;
typedef uint64_t ull;
typedef long double ld;

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve() {
    vector<int> used(10001);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ++used[value];
        if (used[value] < 5 && used[value] % 2 == 0) {
            a.push_back(value);
        }
    }
    sort(a.begin(), a.end());
    ll x = a[0];
    ll y = a[1];
    for (int i = 1; i < a.size() - 1; ++i) {
        if ((a[i] * a[i] + a[i + 1] * a[i + 1]) * x * y < (x * x + y * y) * a[i] * a[i + 1]) {
            x = a[i];
            y = a[i + 1];
        }
    }
    cout << x << " " << x << " " << y << " " << y << "\n";
}

int main() {
    start();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }

    return 0;
}