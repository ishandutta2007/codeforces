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
    int a, b;
    cin >> a >> b;
    int c = abs(a-b);
    if (c == 0) {
        cout << "0 0\n";
    } else {
        int r1 = min(a % c, c - a % c);
        cout << c << ' ' << r1 << '\n';
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