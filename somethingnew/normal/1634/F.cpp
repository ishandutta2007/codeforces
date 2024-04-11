#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
#include "iomanip"
using namespace std;

#define all(x) x.begin(), x.end()
#define int long long
int MOD;
vector<int> good;
vector<int> FIB;

void add(int &x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
    if (x < 0)
        x += MOD;
}
int stpadd(int a, int b) {
    int c = a + b;
    if (c >= MOD)
        return c - MOD;
    return c;
}
vector<int> b;
int goodcnt = 0;
void ch(int v, int x) {
    if (v >= b.size() or v < 2)
        return;
    goodcnt -= (0 == b[v]);
    b[v] += x;
    b[v] %= MOD;
    goodcnt += (0 == b[v]);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n, q;
    cin >> n >> q >> MOD;
    FIB.assign(n + 3, {});
    good.assign(n, {});
    FIB[0] = 1;
    FIB[1] = 1;
    for (int i = 2; i < FIB.size(); ++i) {
        FIB[i] = (FIB[i-2] + FIB[i - 1]) % MOD;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(a[i], -x);
    }
    b.assign(n, 0);
    for (int i = 2; i < n; ++i) {
        b[i] = (0ll + a[i] - a[i-1] - a[i-2]) % MOD;
    }
    pair<int, int> abval = {a[0], a[1]};
    for (int i = 2; i < n; ++i) {
        if (b[i] == 0) {
            goodcnt++;
        }
    }
    for (int i = 0; i < q; ++i) {
        char c = 'A';
        int l = 6, r = 3e5 - 6;
        cin >> c >> l >> r;
        l--;r--;
        if (c == 'A') {
            if (l == 0)
                abval.first++;
            if (l <= 1 and r >= 1)
                abval.second++;
            ch(l, 1);
            int valik = - FIB[r - l];
            if (r != l)
                valik -= FIB[r - l - 1];
            ch(r + 1, valik);
            valik = - FIB[r - l];
            valik %= MOD;
            ch(r + 2, valik);
        }
        else {
            if (l == 0)
                abval.first--;
            if (l <= 1 and r >= 1)
                abval.second--;
            ch(l, -1);
            int valik = - FIB[r - l];
            if (r != l)
                valik -= FIB[r - l - 1];
            ch(r + 1, -valik);
            valik = - FIB[r - l];
            valik %= MOD;
            ch(r + 2, -valik);
        }

        if (n == 1) {
            if (abval.first % MOD == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            if (abval.first % MOD != 0 or abval.second % MOD != 0) {
                cout << "NO\n";
                continue;
            }
            if (goodcnt == n - 2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}