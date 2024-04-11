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
const int N = (int) 3e5 + 5, mod = 0;

int last[N], cnt[N], res[N], pos[N];
pair<pair<int, int>, int> sweep[N];
pair<int, int> p[N];
map<int, int> qpos;
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        pos[i * 2] = p[i].second;
        pos[i * 2 + 1] = p[i].second + k;
        sweep[i * 2] = make_pair(make_pair(p[i].first - k, p[i].second), 1);
        sweep[i * 2 + 1] = make_pair(make_pair(p[i].first, p[i].second), -1);
    }
    sort(pos, pos + 2 * n);
    int m = unique(pos, pos + 2 * n) - pos;
    for (int i = 0; i < m; ++i)
        qpos[pos[i]] = i;
    sort(sweep, sweep + 2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        int x = sweep[i].first.first, l = sweep[i].first.second, r = l + k, add = sweep[i].second;
        int ed = qpos[l];
        while (ed < m && pos[ed] != r) {
            res[cnt[ed]] += (pos[ed + 1] - pos[ed]) * (x - last[ed]);
            cnt[ed] += add;
            last[ed] = x;
            ed++;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';




}