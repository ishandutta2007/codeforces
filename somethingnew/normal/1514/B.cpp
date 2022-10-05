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
long long mod = 1e9 + 7;
void solve() {
    int n, k;
    cin >> n >> k;
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res *= n;
        res %= mod;
    }
    cout << res << endl;
}
signed main() {
    int n;
    cin >> n;
    while (n--) solve();

}