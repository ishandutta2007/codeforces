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

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define double long double
const int N = 0, mod = 0;
double v1, v2, l;
int n, k;

bool check(double lim) {
    int cur = n;
    double pl = 0;
    while (cur > 0) {
        cur -= k;
        double go = pl + lim;
 //       cout << " hi " << pl << ' ' << go << endl;
        if (go > l) return 0;
        if (cur <= 0) return 1;
        double we = pl + (lim / v2) * v1;
        double t = (go - we) / (v1 + v2);
        double aft = we + t * v1;
        pl = aft;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> v1 >> v2 >> k;
    double bl = 0, br = l;
    for (int i = 0; i < 200; ++i) {
        double bm = (bl + br) / 2;
        if (check(bm))
            bl = bm;
        else
            br = bm;
    }
    cout << setprecision(10) << fixed << (l - br) / v1 + br / v2 << endl;
}