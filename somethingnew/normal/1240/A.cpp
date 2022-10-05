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
int x, a, y, b, k;
int slv2(vector<int> p, int cn) {
    int ac = 0, bc = 0, abc = 0;
    for (int i = 1; i <= cn; ++i) {
        if (i % a == 0 and i % b == 0) {
            abc++;
        } else if (i % a == 0) {
            ac++;
        } else if (i % b == 0) {
            bc++;
        }
    }
    int res = 0;
    for (int j = 0; j < abc; ++j) {
        res += p[j] / 100 * (x + y);
    }
    for (int j = abc; j < abc + ac; ++j) {
        res += p[j] / 100 * x;
    }
    for (int j = abc + ac; j < abc + ac + bc; ++j) {
        res += p[j] / 100 * y;
    }
    return res;
}
void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(all(p));
    reverse(all(p));
    cin >> x >> a >> y >> b >> k;
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (slv2(p, m) >= k) {
            r = m;
        } else {
            l = m;
        }
    }
    if (r == n + 1) {
        cout << "-1\n";
    } else {
        cout << r << '\n';
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