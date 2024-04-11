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
#define int long long
const int N = (int) 1e6 + 56, mod = (int) 0;
int n, k, s, t, g[N];
pair<int, int> a[N];
int check(int lim) {
    long long take = 0;
    for (int i = 0; i < k - 1; ++i) {
        int d = g[i + 1] - g[i];
        if (d > lim) {
            return 0;
        }
        if (d * 2 <= lim) {
            take += d;
        } else {
            take += d + 2 * d - lim;
        }
    }
    return take <= t;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> s >> t;
    g[0] = 0;

    g[k + 1] = s;
    k += 2;
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    for (int i = 1; i < k - 1; ++i)
        cin >> g[i];
    sort(g, g + k);
    int bl = 0, br = 2e9 + 1;
    while (bl < br - 1) {
        int bm = bl + br >> 1;
        if (check(bm))
            br = bm;
        else
            bl = bm;
    }
    int mn = 2e9 + 1;
    for (int i = 0; i < n; ++i)
        if (a[i].second >= br)
            mn = min(mn, a[i].first);
    cout << (mn > 1e9? -1: mn) << endl;
    
}