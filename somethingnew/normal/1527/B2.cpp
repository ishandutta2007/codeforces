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

void solve1(int n, string s1) {
    string s2(n, '1');
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
void solve() {
    int n;
    cin >> n;
    string s, s2;
    cin >> s;
    s2 = s;
    reverse(all(s2));
    if (s2 == s) {
        return solve1(n, s);
    }
    int sum = 0;
    for (auto i : s)
        sum += i - '0';
    if (sum == n - 2 and n % 2 == 1 and s[n / 2] == '0') {
        cout << "DRAW\n";
    } else {
        cout << "ALICE\n";
    }
}
signed main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}