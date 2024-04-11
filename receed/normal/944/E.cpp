#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <cmath>
#include <numeric>
#include <deque>
#include <queue>
typedef long long l;
typedef long double ld;
using namespace std;

int n, m, inf = 1e7;

void gis(vector<int> &a, vector<int> &r) {
    vector<int> dp(m + 1, inf);
    r.assign(m, 0);
    dp[0] = 0;
    int cm = 0;
    for (int i = 0; i < m; i++) {
        int t = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[t] == inf)
            cm++;
        dp[t] = a[i];
        r[i] = cm;
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l, r;
    scanf("%d%d",&n, &m);
    vector<pair<int, int>> e;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        e.push_back({l - 1, 1});
        e.push_back({r, -1});
    }
    sort(e.begin(), e.end());
    e.push_back({m, 0});
    vector<int> c(m);
    int ls = 0, cc = 0;
    for (auto pp : e) {
        for (; ls < pp.first; ls++)
            c[ls] = cc;
        cc += pp.second;
    }
    vector<int> r1, r2;
    gis(c, r1);
    reverse(c.begin(), c.end());
    gis(c, r2);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        //ans = max(ans, (i == 0 ? 0 : r1[i - 1]) + (i == m - 1 ? 0 : r2[m - 2 - i]));
        ans = max(ans, r1[i] + r2[m - i - 1] - 1);
    }
    printf("%d", ans);
}