#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
int f(int n) {
    return n / 2 - (n % 2) * n;
}
void solve(){
    int x, n;
    cin >> x >> n;
    if (n == 0) {
        cout << x << '\n';
        return;
    }
    for (int i = n / 4 * 4 + 1; i <= n; ++i) {
        if (x % 2 == 0) {
            x -= i;
        } else {
            x += i;
        }
    }
    cout << x << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}