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
    vector<int> a(n), r, b;
    for (auto &i : a) {
        cin >> i;
    }
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
        if (s[j] == 'R')
            r.push_back(a[j]);
        else
            b.push_back(a[j]);
    }
    sort(all(r));
    reverse(all(r));
    sort(all(b));
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] < i + 1) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < r.size(); ++i) {
        if (r[i] > n - i) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}