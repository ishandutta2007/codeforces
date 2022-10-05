#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include "fstream"
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
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int v = 0;
    for (auto & i : a) {
        cin >> i;
        v ^= i;
    }
    int lval = 0;
    for (int i = 0; i < n; ++i) {
        lval ^= a[i];
        int rval = 0;
        for (int j = n - 1; j > i; --j) {
            rval ^= a[j];
            if (rval == lval and j - 1 == i) {
                cout << "yes\n";
                return;
            }
            if (rval == lval and (v ^ rval) == 0 and j - 1 != i) {
                cout << "yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}
signed main() {
    int n;
    cin >> n;
    while (n--) solve();
}