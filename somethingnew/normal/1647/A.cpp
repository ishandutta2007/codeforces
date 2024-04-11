#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "climits"
#include "queue"
#include "array"
#include "numeric"
#include "random"
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;
    if (n % 3 == 0) {
        for (int i = 0; i < n / 3; ++i) {
            cout << 21;
        }
        cout << '\n';
    } else {
        cout << n % 3;
        for (int i = 0; i < n / 3; ++i) {
            if (n % 3 == 1)
                cout << 21;
            else
                cout << 12;
        }
        cout << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}