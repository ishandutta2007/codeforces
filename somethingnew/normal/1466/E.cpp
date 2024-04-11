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
#define int long long
using namespace std;
vector<int> nums(int a) {
    vector<int> b(60);
    int i = 0;
    while (a) {
        b[i] = a & 1;
        a >>= 1;
        i++;
    }
    return b;
}
void solve(){
    int n;
    cin >> n;
    int mod = 1e9 + 7;
    vector<int> cnt(60);
    vector<vector<int>> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vector<int> bbb = nums(x);
        a.push_back(bbb);
        for (int j = 0; j < 60; ++j) {
            cnt[j] += bbb[j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int left = 0;
        int right = 0;
        for (int bit = 0; bit < 60; ++bit) {
            if (a[i][bit]) {
                left += cnt[bit] * ((1ll << bit) % mod);
                left %= mod;
                right += n * ((1ll << bit) % mod);
                right %= mod;
            } else {
                right += cnt[bit] * ((1ll << bit) % mod);
                right %= mod;
            }
        }
        res += left * right;
        res %= mod;
    }
    cout << res << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}