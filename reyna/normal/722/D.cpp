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
const int N = (int) 1e6 + 6, lg = 30, mod = (int) 0;
int nxt[N][2], val[N], num[N], cnt = 1;
void add(int x) {
    int v = 0;
    int flag = 0;
    for (int i = lg; i >= 0; --i) {
        if (x >> i & 1) flag = 1;
        if (!flag) continue;
        if (!nxt[v][x >> i & 1]) {
            num[cnt] = num[v] * 2 + (x >> i & 1);
            nxt[v][x >> i & 1] = cnt++;
        }
        v = nxt[v][x >> i & 1];
    }
    val[v]++;
}
vector<int> res;
int dfs(int v, int lim) {
    int ret = val[v];
    for (int i = 0; i < 2; ++i)
        if (nxt[v][i])
            ret += dfs(nxt[v][i], lim);
    if (ret >= 1 && num[v] > 0 && num[v] <= lim) {
        ret--;
        res.push_back(num[v]);
    }
    return ret;
}

bool check(int lim) {
    res.clear();
    return dfs(0, lim) == 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(x);
    }
    int bl = 0, br = 1e9 + 9;
    while (bl < br - 1) {
        int bm = bl + br >> 1;
        if (check(bm))
            br = bm;
        else
            bl = bm;
    }
    check(br);
    cerr << br << endl;
    for (int x : res)
        cout << x << ' ';
}