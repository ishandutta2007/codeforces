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

const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;
int f[N];
vector<int> v[N];

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int res = 1;
    f[0] = 1;
    for (int j = 1; j < N; ++j)
        f[j] = f[j - 1] * 1ll * j % mod;
    for (int j = 0; j < n; ++j) {
        int g;
        cin >> g;
        for (int i = 0; i < g; ++i) {
            int x;
            cin >> x;
            x--;
            v[x].push_back(j);
        }
    }
    sort(v, v + m);
    int cnt = 0;
    for (int j = 0; j < m; ++j) {
        cnt++;
        if (j == m - 1 || v[j] != v[j + 1]) {
            res = res * 1ll * f[cnt] % mod;
            cnt = 0;
        }
    }
    cout << res << endl;
}