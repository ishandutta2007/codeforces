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
#include "queue"
#define all(x) x.begin(), x.end()
using namespace std;

array<int, 3> slvseg(vector<int> a) {
    int n = a.size();
    int l = 0, r = n, res = 0;
    int minotr = 0, potr = 0;
    int allres = 0;
    for (int i = n - 1; i >= 0; --i) {
        potr++;
        if (abs(a[i]) == 2)
            minotr++;
        if (a[i] < 0)
            break;
    }
    int zn = 1;
    for (int i = 0; i < n; ++i) {
        if (abs(a[i]) == 2) allres++;
        if (a[i] < 0)
            zn = 1 - zn;
    }
    for (int i = 0; i < n; ++i) {
        if (zn == 1) {
            if (allres > res) {
                res = allres;
                l = i;
                r = 0;
            }
        } else {
            if (allres - minotr > res) {
                res = allres - minotr;
                l = i;
                r = potr;
            }
        }
        allres -= (abs(a[i]) == 2);
        if (a[i] < 0)
            zn = 1 - zn;
    }
    return {res, l, r};
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int lans = 0, rans = n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0)
            continue;
        int j = i;
        while (a.size() != j and a[j] != 0)
            j++;
        vector<int> b;
        for (int k = i; k < j; ++k) {
            b.push_back(a[k]);
        }
        auto [an, ll, rr] = slvseg(b);
        if (ans < an) {
            ans = an;
            lans = ll + i;
            rans = rr + (n - j);
        }
        i = j;
    }
    cout << lans << ' ' << rans << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
/*

 */