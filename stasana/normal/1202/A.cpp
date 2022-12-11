#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;
typedef long double ld;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int x = -1;
    int y = -1;
    for (int i = 0; i < (int)b.size(); ++i) {
        if (b[i] == '1') {
            y = i;
            break;
        }
    }
    for (int i = y; i < (int)a.size(); ++i) {
        if (a[i] == '1') {
            x = i;
            break;
        }
    }

    if (x == -1 || y == -1) {
        cout << 0 << "\n";
        return;
    }
    cout << x - y << "\n";
}

int main() {
    start();
    int n;
    cin >> n;
    while (n) {
        --n;
        solve();
    }
    return 0;
}