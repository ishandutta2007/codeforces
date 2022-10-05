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
#include "queue"

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n;
    cin >> n;
    int res = 0;
    for (char i = '1'; i <= '9'; ++i) {
        string s;
        for (int j = 0; j <= 12; ++j) {
            s.push_back(i);
            if (n >= stoll(s)) {
                res++;
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}