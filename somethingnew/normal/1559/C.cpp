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

void solve() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &i : a)
       cin >> i;
   if (a[0] == 1) {
       cout << n + 1 << ' ';
       for (int i = 0; i < n; ++i) {
           cout << i + 1 << ' ';
       }
       cout << '\n';
       return;
   }
   bool ok = 0;
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ' ';
        if (!ok and (i + 1 == n or a[i + 1] == 1)) {
            cout << n + 1 << ' ';
            ok = 1;
        }
    }
    cout << '\n';
}
signed main() {
    int n;
    cin >> n;
    while (n--) solve();
}