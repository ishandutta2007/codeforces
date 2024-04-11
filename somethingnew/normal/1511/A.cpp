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
#define ll long long
using namespace std;
void solve() {
    int c = 0;
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        c += (k != 2);
    }
    cout << c << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}