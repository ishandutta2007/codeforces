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
#define int long long
const int N = 1e5 + 5, mod = 0;

int a[N];

map<int, pair<int, int>> res;

pair<int, int> best(int x) {
    if (x == 0)
        return make_pair(0, 0);
    if (res.find(x) != res.end())
        return res[x];
    int pick = upper_bound(a, a + N, x) - a - 1;
    pick = a[pick];
    pair<int, int> l = best(x - pick);
    l.first += 1;
    l.second += pick;
    l = max(l, best(pick - 1));
    return res[x] = l;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < N; ++i)
        a[i] = i * i * i;
    int n;
    cin >> n;
    cout << best(n).first << ' ' << best(n).second << endl;
}