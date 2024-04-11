#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
vector<vector<pair<int, int>>> g;
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    int res = 0;
    cin >> n;
    vector<pair<int, int>> elems(n);
    for (auto &[l, r] : elems) {
        cin >> l >> r;
        res += r;
    }
    elems[0].second = -elems[0].second - 10;
    sort(all(elems));
    int s = -1;
    for (int i = 0; i < n; ++i) {
        if (elems[i].second < 0) {
            elems[i].second += 10;
            elems[i].second = -elems[i].second;
            s = i;
        }
    }
    g.assign(n, {});
    for (int i = 1; i < n; ++i) {
        g[i].push_back({i-1, 0});
    }
    for (int i = 0; i < n; ++i) {
        int flup = elems[i].first + elems[i].second;
        int l = i, r = n;
        while (l + 1 < r) {
            int m = l + r >> 1;
            if (elems[m].first <= flup) {
                l = m;
            } else {
                r = m;
            }
        }
        //cout << i << ' ' << l << endl;
        g[i].push_back({l, 0});
        if (r != n) {
            g[i].push_back({r, max(elems[i].second, elems[r].first - elems[i].first) - elems[i].second});
        }
    }
    vector<int> price(n, -1);
    priority_queue<pair<int, int>> que;
    que.push({0, s});
    while (!que.empty()) {
        int v = que.top().second;
        int pr = que.top().first;
        que.pop();
        if (price[v] == -1) {
            price[v] = -pr;
            for (auto [u, prc] : g[v]) {
                que.push({-price[v] - prc, u});
            }
        }
    }
    int res1 = price.back();
    vector<int> price2(n, -1);
    priority_queue<pair<int, int>> que2;
    que2.push({0, 0});
    while (!que2.empty()) {
        int v = que2.top().second;
        int pr = que2.top().first;
        que2.pop();
        if (price2[v] == -1) {
            price2[v] = -pr;
            for (auto [u, prc] : g[v]) {
                que2.push({-price2[v] - prc, u});
            }
        }
    }
    int res2 = price2[s];
    cout << res1 + res + res2;

}