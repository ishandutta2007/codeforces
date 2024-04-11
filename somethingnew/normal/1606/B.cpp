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
void solve(){
    int t = 0;
    int n, k;
    cin >> n >> k;
    int res = 1;
    while (res < min(n, k + 1)) {
        res *= 2;
        t++;
    }
    if (res >= n) {
        cout << t << '\n';
        return;
    }
    t += (n - res + k - 1) / k;
    cout << t << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}