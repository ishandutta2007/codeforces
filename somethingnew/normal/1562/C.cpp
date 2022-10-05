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

void solve(){
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (i >= n / 2) {
                cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << '\n';
                return;
            } else {
                cout << i + 2 << ' ' << n << ' ' << i + 1 << ' ' << n << '\n';
                return;
            }
        }
    }
    cout << 1 << ' ' << n / 2 << ' ' << 2 << ' ' << n / 2 + 1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}