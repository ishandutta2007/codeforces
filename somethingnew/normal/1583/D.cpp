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
int zpr1(int n, int a, int b) {
    cout << "? ";
    for (int i = 0; i < n - 1; ++i) {
        cout << b << ' ';
    }
    cout << a;
    cout << endl;
    int x;
    cin >> x;
    return x;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int res = n;
    for (int i = n; i > 1; --i) {
        if (zpr1(n, i, 1) != 0) {
            res = n - i + 1;
            break;
        }
    }
    vector<int> ans(n);
    ans.back() = res;
    for (int j = 1; j <= n; ++j) {
        if (j == res)
            continue;
        // j + b == res + a
        // j - res == a - b
        int jr = j - res;
        int a = 1;
        int b = 1;
        if (jr < 0)
            b = 1 - jr;
        else
            a = 1 + jr;
        int x = zpr1(n, a, b);
        x--;
        ans[x] = j;
    }
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}