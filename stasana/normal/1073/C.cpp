//    -
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int x, y;
    cin >> x >> y;
    if (abs(x) + abs(y) > n) {
        cout << -1;
        return 0;
    }
    if ((n - abs(x) - abs(y)) % 2 == 1) {
        cout << -1;
        return 0;
    }
    vector<int> up(n + 1);
    vector<int> dw(n + 1);
    vector<int> lf(n + 1);
    vector<int> rt(n + 1);
    for (int i = 1; i <= n; ++i) {
        up[i] = up[i - 1];
        rt[i] = rt[i - 1];
        lf[i] = lf[i - 1];
        dw[i] = dw[i - 1];
        if (s[i] == 'U') {
            ++up[i];
        }
        if (s[i] == 'R') {
            ++rt[i];
        }
        if (s[i] == 'L') {
            ++lf[i];
        }
        if (s[i] == 'D') {
            ++dw[i];
        }
    }
    int res = 1e9;
    if (up.back() - dw.back() == y && rt.back() - lf.back() == x) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        int left  = i - 1;
        int right = n + 1;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            int yy = up[i - 1] - dw[i - 1] + up.back() - up[mid] - dw.back() + dw[mid];
            int xx = rt[i - 1] - lf[i - 1] + rt.back() - rt[mid] - lf.back() + lf[mid];
            if (mid - i + 1 >= abs(xx - x) + abs(yy - y)) {
                right = mid;
            }
            else {
                left  = mid;
            }
        }
        if (right != n + 1) {
            res = min(res, right - i + 1);
        }
    }
    cout << res;
    return 0;
}