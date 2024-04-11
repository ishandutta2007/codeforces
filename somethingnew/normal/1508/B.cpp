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
    cin >> n;
    long long k;
    cin >> k;
    k--;
    vector<int> ans(n);
    ans[n - 1] = n;
    for (int i = 0; i < n - 63; ++i) {
        ans[i] = i + 1;
    }
    for (int i = max(0, n - 63); i < n - 1; ++i) {
        long long t = 1ll << (n - i - 2);
        int p = i;
        while (t <= k) {
            k -= t;
            p++;
            t /= 2;
            if (t == 0) {
                break;
            }
        }
        if (p >= n) {
            cout << "-1\n";
            return;
        }
        for (int j = p; j >= i; --j) {
            ans[j] = i + p - j + 1;
        }
        i = p;
    }
    if (k != 0) {
        cout << "-1\n";
        return;
    }
    for (int l = 0; l < n; ++l) {
        cout << ans[l] << ' ';
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}