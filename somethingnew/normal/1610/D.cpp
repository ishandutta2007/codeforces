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
int mod = 1e9 + 7;
int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b % 2) {
            res *= a;res %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}
void solve(){
    vector<int> deg(40);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;cin >> x;
        int k = 0;
        while (x % 2 == 0) {
            x /= 2;
            k++;
        }
        deg[k]++;
    }
    int res = 0;
    int cnt = n;
    for (int i = 0; i < 40; ++i) {
        cnt -= deg[i];
        if (deg[i]) {
            if (i == 0)
                res += (pw(2, deg[i]) - 1) * pw(2, cnt) % mod;
            else
                res += (pw(2, deg[i] - 1) - 1) * pw(2, cnt) % mod;
        }
    }
    cout << res % mod;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}