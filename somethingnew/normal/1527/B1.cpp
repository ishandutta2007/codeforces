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
    string s1, s2(n, '1');
    cin >> s1;
    if (s1 == s2) {
        cout << "DRAW\n";
        return;
    }
    if (n % 2 == 0 or s1[n / 2] == '1') {
        cout << "BOB\n";
    } else {
        s2[n / 2] = '0';
        if (s1 == s2) {
            cout << "BOB\n";
        } else {
            cout << "ALICE\n";
        }
    }
}
signed main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}