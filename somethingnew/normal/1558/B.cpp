#include <iostream>
#include <vector>
#include "stack"
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "climits"
#include "map"
#include "cassert"
//#define _GLIBCXX_DEBUG
#define int long long

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-6;

int n, m;
vector<int> t;

int pl(int a, int b) {
    if (a + b >= m) return a + b - m;
    return a + b;
}

int sum(int r) {
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result = pl(result, t[r]);
    return result;
}

void inc(int i, int delta) {
    for (; i < n + 2; i = (i | (i+1)))
        t[i] = pl(t[i], delta);
}

signed main() {
    ios::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    t.assign(n + 2, 0);
    inc(1, 1);
    inc(2, -1);//ss
    for (int i = 1; i < n; i++) {
        int now = sum(i);
        inc(i + 1, now);
        for (int x = 2; x * i <= n; x++) {
            inc(x * i, now);
            inc(min(x * i + x, n + 1), m-now);
        }
    }
    cout << sum(n);
}