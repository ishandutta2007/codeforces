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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == i + 1)
            continue;
        else {
            int j = i;
            while (a[j] != i + 1) j++;
            while (i < j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
            break;
        }
    }
    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}