#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int LOGN = 20;

int func(int x, int y, bool cmp) {
    if (cmp) {
        return max(x, y);
    }
    return min(x, y);
}

struct Tree {
    int n;
    bool cmp;
    vector <int> t;
    Tree() {}
    void build(vector <int> &a, bool cmp) {
        n = a.size();
        t.resize(2 * n, 0);
        this->cmp = cmp;
        //cout << n << " " << a.size() << "\n";
        for (int i = 0; i < n; i++) {
            t[i + n] = a[i];
        }
        for (int i = n - 1; i >= 1; i--) {
            t[i] = func(t[2 * i], t[2 * i + 1], cmp);
        }
    }
    int get(int l, int r) {
        int res = (cmp ? -INF : INF);
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) {
                res = func(res, t[l++], cmp);
            }
            if (r % 2 == 0) {
                res = func(res, t[r--], cmp);
            }
        }
        return res;
    }
};

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> l(3 * n), r(3 * n);
    for (int i = 0; i < 3 * n; i++) {
        l[i] = max(0, i - a[i % n]);
        r[i] = min(3 * n - 1, i + a[i % n]);
    }
    vector <vector <int> > binl(LOGN, vector <int> (3 * n, 0));
    vector <vector <int> > binr(LOGN, vector <int> (3 * n, 0));
    binl[0] = l;
    binr[0] = r;
    for (int t = 1; t < LOGN; t++) {
        Tree tl, tr;
        tl.build(binl[t - 1], false);
        tr.build(binr[t - 1], true);
        for (int pos = 0; pos < 3 * n; pos++) {
            int lnow = binl[t - 1][pos], rnow = binr[t - 1][pos];
            //cout << t << " " << pos << " " << lnow << " " << rnow << "\n";
            binl[t][pos] = tl.get(lnow, rnow);
            binr[t][pos] = tr.get(lnow, rnow);
        }
    }
    vector <pair <int, int> > seg(3 * n);
    for (int i = 0; i < 3 * n; i++) {
        seg[i] = {i, i};
    }
    vector <int> res(n, 0);
    for (int t = LOGN - 1; t >= 0; t--) {
        Tree tl, tr;
        tl.build(binl[t], false);
        tr.build(binr[t], true);
        for (int i = 0; i < n; i++) {
            int pos = i + n;
            int l = seg[pos].first, r = seg[pos].second;
            int ln = tl.get(l, r), rn = tr.get(l, r);
            if (rn - ln + 1 >= n) continue;
            //cout << t << " " << pos << " " << ln << " " << rn << "\n";
            seg[pos] = {ln, rn};
            res[i] += 1 << t;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] + 1 << " ";
    }
}