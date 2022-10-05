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
#define int long long
using namespace std;
bool sqa(int x) {
    int t = sqrt(x);
    for (int i = t - 5; i < t + 6; ++i) {
        if (i * i == x)
            return 1;
    }
    return 0;
}
void solve(){
    int n;
    cin >> n;
    if (n % 2) {
        cout << "NO\n";
        return;
    }
    n /= 2;
    while (1) {
        if (sqa(n)) {
            cout << "YES\n";
            return;
        }
        if (n % 2) {
            cout << "NO\n";
            return;
        }
        n /= 2;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}