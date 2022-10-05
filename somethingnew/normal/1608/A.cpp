#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#define all(a) (a).begin(), (a).end()
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << i + 2 << ' ';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
        solve();
}