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
int pow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b % 2) {
            res *= a;
            res %= mod;
        }
        b /= 2;
        a *= a;
        a %= mod;
    }
    return res;
}
int inv(int a, int mod) {
    return pow(a, mod - 2, mod);
}
int findcnk(int n, int k, int mod) {
    int res1 = 1, res2 = 1;
    if (k > n)
        return 1;
    for (int i = n - k + 1; i <= n; ++i) {
        res1 *= i;
        res1 %= mod;
        res2 *= i - n + k;
        res2 %= mod;
    }
    res1 *= inv(res2, mod);
    res1 %= mod;
    return res1;
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> pos(n + 1);
    vector<int> table(n);
    pos[n] = -1;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        table[i] = v;
        pos[v] = i;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (pos[table[i] + 1] > pos[table[i + 1] + 1]) {
            k--;
            //cout << i << endl;
        }
    }
    if (k <= 0) {
        cout << 0;
        return;
    }
    //cout << k << endl;
    cout << findcnk(n + k - 1, k - 1, 998244353);
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}