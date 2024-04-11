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
#define int ll
void solve() {
    int n;
    cin >> n;
    vector<int> pole(n);
    int s = 0;
    for (auto &i : pole) {
        char t;
        cin >> t;
        if (t == '*') {
            i = 1;
            s++;
        }
    }
    if (s == 0) {
        cout << "0\n";
        return;
    }
    int leftsz = 1;
    int rightsz = 1;
    int leftind = -1, rightind = -1;
    for (int i = 0; i < n; ++i) {
        if (pole[i]) {;
            leftind = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (pole[i]) {
            rightind = i;
            break;
        }
    }
    int res = 0;
    while (leftind != rightind) {
        if (leftsz < rightsz) {
            leftind++;
            if (pole[leftind]) {
                leftsz++;
            } else{
                res += leftsz;
            }
        } else {
            rightind--;
            if (pole[rightind]) {
                rightsz++;
            } else{
                res += rightsz;
            }
        }
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}