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
int m, n, p[N], mark[N];
string s, t;
bool check(int lim) {
    memset(mark, 0, sizeof mark);
    for (int j = 0; j < lim; ++j)
        mark[p[j]] = 1;
    int pt = 0;
    for (int j = 0; j < n; ++j) if (!mark[j]) {
        if (pt < m && s[j] == t[pt])
            pt++;
    }
    return pt == m;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> t;
    n = (int) s.size(), m = (int) t.size();
    for (int j = 0; j < n; ++j)
        cin >> p[j], --p[j];
    int bl = 0, br = n;
    while (bl < br - 1) {
        int bm = bl + br >> 1;
        if (check(bm))
            bl = bm;
        else
            br = bm;
    }
    cout << bl << endl;
}