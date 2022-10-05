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
    int n;
    cin >> n;
    int c = 0;
    int add = 1e9;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            int x;cin >> x;
            if (i < n and j < n)
                c += x;
            if (i >= n and j >= n)
                c += x;
            if (i == 0 and j == n)
                add = min(add, x);
            if (i == n and j == 0)
                add = min(add, x);
            if (i == n and j == n - 1)
                add = min(add, x);
            if (i == n - 1 and j == n)
                add = min(add, x);
            if (i == n - 1 and j == 2 * n - 1)
                add = min(add, x);
            if (j == n - 1 and i == 2 * n - 1)
                add = min(add, x);
            if (i == n * 2 - 1 and j == 0)
                add = min(add, x);
            if (j == n * 2 - 1 and i == 0)
                add = min(add, x);
        }
    }
    cout << c + add << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}