#include "list"
#include <iostream>
#include "queue"
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
int div(int x) {
    int res = 0;
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            res++;
            x /= i;
        }
    }
    if (x != 1)
        return res+1;
    return res;
}
void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 1) {
        if ((a % b == 0 or b % a == 0) and a != b) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }
    if (div(a) + div(b) >= k) {
        cout << "yes\n";
        return;
    }
    cout << "NO\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}