#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a;
    vector<int> b;
    vector<int> d;
    forn (i, n) {
        int x;
        cin >> x;
        d.pb(x);
        if (a.size() == 0) {
            a.pb(x);
            b.pb(1);
            continue;
        }
        if (a.back() == x) {
            a.pb(x);
            b.pb(b.back() + 1);
        } else {
            a.pb(x);
            b.pb(1);
        }
        if (b.back() == k) {
            forn (j, k) {
                a.pop_back();
                b.pop_back();
            }
        }
    }
    if (m == 2) {
        forn (i, n) {
            int x = d[i];
            if (a.size() == 0) {
                a.pb(x);
                b.pb(1);
                continue;
            }
            if (a.back() == x) {
                a.pb(x);
                b.pb(b.back() + 1);
            } else {
                a.pb(x);
                b.pb(1);
            }
            if (b.back() == k) {
                    forn (j, k) {
                    a.pop_back();
                    b.pop_back();
                }
            }
        }
    }
    n = a.size();
    if (m <= 2 || n == 0) {
        cout << n << endl;
        return 0;
    }
    vector<int> c(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] == a[i + 1]) {
            c[i] = c[i + 1] + 1;
        }
    }
    int l = 0, r = n;
    while (r - l > b[r - 1]) {
        if (a[l] == a[r - 1] && b[r - 1] + c[l] >= k) {
            int cur = min(k, b[r - 1]);
            r -= cur;
            l += k - cur;
        } else {
            cout << n - l + r + (long long)(m - 2) * (r - l) << endl;
            return 0;
        }
    }
    long long cnt = (long long)(r - l) * (m - 2) + b[r - 1] + c[l];
    cnt %= k;
    if (cnt) {
        cout << r - b[r - 1] + n - l - c[l] + cnt << endl;
        return 0;
    }
    d.clear();
    forn (i, r - b[r - 1]) {
        d.pb(a[i]);
    }
    forn (i, n - l - c[l]) {
        d.pb(a[l + c[l] + i]);
    }
    a.clear();
    b.clear();
    forn (i, d.size()) {
        int x = d[i];
        if (a.size() == 0) {
            a.pb(x);
            b.pb(1);
            continue;
        }
        if (a.back() == x) {
            a.pb(x);
            b.pb(b.back() + 1);
        } else {
            a.pb(x);
            b.pb(1);
        }
        if (b.back() == k) {
            forn (j, k) {
                a.pop_back();
                b.pop_back();
            }
        }
    }
    cout << a.size() << endl;
    return 0;
}