// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 1e6 + 6, mod = (int) 0;
int n, w, k, a[N], t[N];
set<pair<int, int>> x, y;
int r, pl, tl, ts, res;
void fix() {
    while (x.size() > 0 && y.size() > 0) {
        auto p = *(x.rbegin());
        auto q = *(y.begin());
        if (p.first > q.first) {
            x.erase(p);
            y.insert(p);
            ts += p.first / 2;
            x.insert(q);
            y.erase(q);
            ts -= q.first / 2;
        } else {
            break;
        }
    } 
    while (x.size() > 0 && y.size() < w) {
        auto it = *(x.rbegin());
        ts += it.first / 2;
        y.insert(it);
        x.erase(it);
    }
}
void add(int r) {
    x.insert(make_pair(t[r], r));
    pl += a[r];
    tl += t[r];
    fix();
}
void rem(int l) {
    pl -= a[l];
    tl -= t[l];
    if (y.find(make_pair(t[l], l)) != y.end()) {
        ts -= t[l] / 2;
        y.erase(make_pair(t[l], l));
    } else {
        x.erase(make_pair(t[l], l));
    }
    fix();
}
bool check(int lim) {
    x.clear();
    y.clear();
    r = 0, pl = 0, tl = 0, ts = 0, res = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && tl - ts <= k) {
            add(r);
            r++;
        }
        if (tl - ts > k) {
            rem(r - 1);
            r--;
        }
        res = max(res, pl);
        rem(l);
    }
    return 0;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> w >> k;
    for (int j = 0; j < n; ++j)
        cin >> a[j];
    for (int j = 0; j < n; ++j)
        cin >> t[j];
    reverse(a, a + n);
    reverse(t, t + n);
/*    long long bl = 0, br = 2e9 + 1;
    while (bl < br - 1) {
        long long bm = (bl + br) >> 1;
        if (check(bm))
            bl = bm;
        else
            br = bm;
    }*/
    check(0);
    cout << res << endl;
}