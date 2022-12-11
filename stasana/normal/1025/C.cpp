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

int main() {
    start();

    int n;
    string s;
    cin >> s;
    n = s.length();
    vector<int> a(n, 1);
    vector<int> b(n, 1);
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            a[i] = a[i - 1] + 1;
        }
    }
    reverse(s.begin(), s.end());
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            b[i] = b[i - 1] + 1;
        }
    }
    if (a.back() == n) {
        cout << n;
        return 0;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(a[i], res);
    }
    if (s[0] != s.back()) {
        res = max(res, a.back() + b.back());
    }
    cout << res;
    return 0;
}