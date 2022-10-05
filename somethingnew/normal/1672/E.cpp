#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
vector<int> lna = {5,2,7,3,5,6};
int retzp(int w) {
    int res = 0;
    int ost = 0;
    for (auto i : lna) {
        if (i > w) {
            return 0;
        }
        if (i > ost) {
            ost = w;
            res++;
        }
        ost -= i + 1;
    }
    return res;
}
int zpr(int w) {
    cout << "? " << w << endl;
    int x;
    cin >> x;
    return x;
}
void solve() {
    int ans = 1e16;
    int n;
    cin >> n;
    int l = 0, r = 2040 * n;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (zpr(m) == 1) {
            r = m;
        } else {
            l = m;
        }
    }
    int sm = r - n + 1;
    //cerr << sm << endl;
    ans = r;
    for (int i = 0; i < n; ++i) {
        int I = (sm + n - 1) / (n - i);
        int zp = zpr(I);
        if (zp != 0)
            ans = min(ans, zp * I);

    }
    cout << "! " << ans << endl;
}
/*
int stup(int n) {
    int ans = 1e18;
    for (int i = 0; i < n * 2000 + 200; ++i) {
        int zp = zpr(i);
        if (zp != 0)
            ans = min(ans, zp * i);
    }
    return ans;
}
void strs() {
    int n = rand() % 40 + 2;
    lna.clear();
    for (int i = 0; i < n; ++i) {
        lna.push_back(rand() % 2000 + 3);
    }
    if (solve(n) != stup(n)) {
        cout << n << endl;
        exit(0);
    } else {
        cout << "OK\n";
    }
}*/
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}