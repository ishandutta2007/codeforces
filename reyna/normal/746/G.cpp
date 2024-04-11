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
int a[N], par[N];
set<int> st[N];
vector<int> all[N], ax, bx;
void add_edge(int x, int y) {
    ax.push_back(x + 1);
    bx.push_back(y + 1);
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t, k;
    cin >> n >> t >> k;
    int cnt = t + 1;
    for (int j = 0; j < t; ++j) {
        cin >> a[j];
        for (int i = 0; i < a[j] - 1; ++i) {
            st[j].insert(cnt);
            all[j].push_back(cnt);
            par[cnt] = j;
            cnt++;
        }
    }
    if (t == 1) {
        if (k != n - 1) {
            cout << -1 << endl;
            return 0;
        }
    }
  
    for (int j = 0; j < t; ++j)
        add_edge(j, j + 1);
    if (n - t < k) {
        cout << -1 << endl;
        return 0;
    }
    int cur = n - t;
    for (int j = t - 1; cur > k && j >= 1; --j) {
        for (int u : all[j]) if (st[j - 1].size() > 0) {
            int v = *(st[j - 1].begin());
            par[u] = v;
            st[j - 1].erase(v);
            cur--;
            if (cur == k) {
                break;
            }
        }
    }
    if (cur != k) {
        cout << -1 << endl;
        return 0;
    }
    for (int j = t + 1; j < n; ++j)
        add_edge(par[j], j);
    cout << n << endl;
    for (int j = 0; j < n - 1; ++j) {
        cout << ax[j] << ' ' << bx[j] << '\n';
    }

}