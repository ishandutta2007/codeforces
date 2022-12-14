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

const int N = (int) 1e5 + 5, mod = 0;

int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(b, b + m);
    int ed = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        while (ed < m - 1 && b[ed + 1] <= a[i])
            ++ed;
        res = max(res, min(abs(a[i] - b[ed]), (ed + 1 == m? (int) 2e9: abs(a[i] - b[ed + 1]))));
    }
    cout << res << endl;
}