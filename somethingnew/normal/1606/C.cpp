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
#define int long long
void solve(){
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> nums(n);
    vector<int> prc(19, -1);
    for (auto i : nums) {
        cin >> i;
        prc[i] = 1;
    }
    for (int i = 1; i < 19; ++i) {
        if (prc[i] == -1)
            prc[i] = prc[i - 1] * 10;
    }
    vector<int> prefs(20);
    prefs[0] = 0;
    vector<int> ans(19);
    for (int j = 0; j < 19; ++j) {
        prefs[j+1] = prefs[j] + prc[j] * 9;
    }
    for (int i = 0; i < 19; ++i) {
        if (prefs[i + 1] >= k) {
            int ii = i;
            while (i >= 0) {
                //cerr << k << '\n';
                ans[i] = (k - prefs[i] + prc[i] - 1) / prc[i];
                k -= (k - prefs[i] + prc[i] - 1) / prc[i] * prc[i];
                i--;
            }
            for (i = ii; i >= 0; --i) {
                cout << ans[i];
            }
            cout << '\n';
            return;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}