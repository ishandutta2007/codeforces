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
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto & i : a)
        cin >> i;
    for (auto & i : b)
        cin >> i;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += a[i] * b[i];
    }
    int mxr = res;
    for (int i = 0; i < n; ++i) {
        int rp = res;
        for (int j = 1; j < n; ++j) {
            if (i - j < 0 or i + j >= n)
                break;
            rp -= a[i - j] * b[i - j];
            rp -= a[i + j] * b[i + j];
            rp += a[i - j] * b[i + j];
            rp += a[i + j] * b[i - j];
            mxr = max(mxr, rp);
        }
    }
    for (int i = 0; i < n; ++i) {
        int rp = res;
        for (int j = 1; j < n; ++j) {
            if (i - j + 1 < 0 or i + j >= n)
                break;
            rp -= a[i - j + 1] * b[i - j + 1];
            rp -= a[i + j] * b[i + j];
            rp += a[i - j + 1] * b[i + j];
            rp += a[i + j] * b[i - j + 1];
            mxr = max(mxr, rp);
        }
    }
    cout << mxr << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n = 1;//cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}