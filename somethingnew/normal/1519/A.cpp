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
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;

void solve(){
    int r, b, d;
    cin >> r >> b >> d;
    pair<int, int> p = minmax(r, b);
    if (p.first * (d + 1) >= p.second) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}