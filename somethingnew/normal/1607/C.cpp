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
    vector<int> a(n);
    for (auto  &i : a)
        cin >> i;
    sort(all(a));
    int vic = 0;
    int mn = a[0];
    for (int j = 0; j < n - 1; ++j) {
        vic += (a[j] - vic);
        mn = max(mn, a[j + 1] - vic);
    }
    cout << mn << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}