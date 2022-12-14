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
const int N = 0, mod = 0;
map<int, int> cost;
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int c;
        cin >> c;
        if (c == 1) {
            int u, v, w;
            cin >> u >> v >> w;
            while (u != v) {
                if (u > v)
                    swap(u, v);
                cost[v] += w;
                v >>= 1;
            }
        } else {
            int u, v;
            cin >> u >> v;
            int res = 0;
            while (u != v) {
                if (u > v)
                    swap(u, v);
                res += cost[v];
                v >>= 1;
            }
            cout << res << '\n';
        }
    }





}