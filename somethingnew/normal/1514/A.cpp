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
    int n;
    cin >> n;
    bool gd = false;
    for (int i = 0; i < n; ++i) {
        int t;
        bool bg = false;
        cin >> t;
        for (int j = 0; j * j <= t; ++j) {
            if (j * j == t)
                bg = true;
        }
        if (!bg)
            gd = true;
    }
    if (!gd)
        cout << "NO\n";
    else
        cout << "YES\n";
}
signed main() {
    int n;
    cin >> n;
    while (n--) solve();

}