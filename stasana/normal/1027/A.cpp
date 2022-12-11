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

typedef int64_t ll;
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (abs(s[i] - s[n - i - 1]) != 2 && abs(s[i] - s[n - i - 1]) != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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