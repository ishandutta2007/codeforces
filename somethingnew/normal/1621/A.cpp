#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#include "deque"
#define int long long
using namespace std;
void solve() {
    int k, n;
    cin >> n >> k;
    if (k * 2 - 1 > n) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j and i % 2 == 0 and i / 2 < k)
                cout << "R";
            else
                cout << ".";
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