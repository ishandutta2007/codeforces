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
void solve(){
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n * 2; ++i) {
        int x, y;
        cin >> x >> y;
        x = abs(x);
        y = abs(y);
        if (x == 0)
            b.push_back(y);
        if (y == 0)
            a.push_back(x);
    }
    sort(all(a));
    sort(all(b));
    long double res = 0;
    for (int j = 0; j < n; ++j) {
        res += hypot(a[j], b[j]);
    }
    cout << setprecision(20) << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}