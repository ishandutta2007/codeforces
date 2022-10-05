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
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        res += x;
        res %= n;
    }
    cout << res * (n - res) << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}