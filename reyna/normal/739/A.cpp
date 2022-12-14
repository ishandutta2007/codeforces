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

const int N = (int) 0, mod = (int) 0;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int res = 1e9;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        res = min(res, r - l + 1);
    }
    cout << res << endl;
    for (int i = 0; i < n; ++i)
        cout << i % res << ' ';

}