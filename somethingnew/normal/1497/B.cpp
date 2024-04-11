#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"

#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        t %= m;
        //cerr << t << endl;
        a[t]++;
    }
    int res = (a[0] != 0);
    for (int i = 1; i < m; ++i) {
        //cout << a[i] << ' ' << res << endl;
        if (m - i == i){
            res += (a[i] != 0);
        }
        if (m - i <= i)
            break;
        res += (a[i] + a[m - i] != 0);
        res += max(a[i], a[m - i]) - min(a[i], a[m - i]) - (a[m - i] != a[i]);
        //cout << res << endl;
    }
    cout << res << '\n';
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}