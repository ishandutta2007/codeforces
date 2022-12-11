#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << 2 << endl;
    } else {
        cout << (n & 1) << endl;
    }
}

int main() {
    start();
    int n;
    cin >> n;
    while (n) {
        --n;
        solve();
    }
    //solve();
    return 0;
}