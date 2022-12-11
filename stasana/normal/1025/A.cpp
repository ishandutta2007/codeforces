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
    cin >> n;
    vector<int> a(26);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        ++a[s[i] - 'a'];
    }
    int mx = 0;
    for (int i = 0; i < 26; ++i) {
        mx = max(mx, a[i]);
    }
    if (n == 1) {
        cout << "Yes";
        return 0;
    }
    if (mx < 2) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
    return 0;
}