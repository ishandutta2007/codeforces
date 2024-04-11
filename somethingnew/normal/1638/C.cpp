#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
using namespace std;
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;
    int cnt = 0, x = 0;
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        if (y > x) {
            if (x == i)
                cnt++;
            x = y;
        }
    }
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}