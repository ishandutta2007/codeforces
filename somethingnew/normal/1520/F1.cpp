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
#include "queue"

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
map<pair<int, int>, int> reszp;

int zapr(int l, int r) {
    if (reszp[{l, r}])
        return reszp[{l, r}];
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    int x;
    cin >> x;
    reszp[{l, r}] = r - l + 2 - x;
    return r - l + 1 - x;
}
void solve() {
    int n;
    cin >> n;
    int t;
    cin >> t;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = n;
        int k;
        cin >> k;
        while (l + 1 != r) {
            int m = (l + r) / 2;
            int x = zapr(l, m - 1);
            if (x < k) {
                k -= x;
                l = m;
            } else {
                r = m;
                reszp[{l, r}]--;
            }
        }
        cout << "! " << r << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}