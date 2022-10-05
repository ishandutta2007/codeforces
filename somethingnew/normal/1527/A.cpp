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
#include "array"
#include "queue"
#include "map"
using namespace std;
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;
    int k;
    k = 1;
    while (k <= n)
        k *= 2;
    k /= 2;
    k -= 1;
    cout << k << endl;
}
signed main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}