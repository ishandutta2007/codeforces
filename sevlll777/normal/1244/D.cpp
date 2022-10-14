#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
using namespace std;
int a, b, c, d, n, m, k, x, r, l, q, i, j, v1, v2, p, y, w;
string s, t;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> c1;
    vector<int> c2;
    vector<int> c3;
    for (int i = 0; i < n; i++) {
        cin >> x;
        c1.pb(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        c2.pb(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        c3.pb(x);
    }
    vector<vector<int>> C;
    C.pb(c1);
    C.pb(c2);
    C.pb(c3);
    unmp<int, unst<int>> graph;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    int strt;
    for (auto pie : graph) {
        if (pie.second.size() >= 3) {
            cout << -1;
            return 0;
        } else if (pie.second.size() == 1) {
            strt = pie.first;
        }
    }
    vector<tupint > P;
    P.pb({0, 1, 2});
    P.pb({0, 2, 1});
    P.pb({1, 0, 2});
    P.pb({1, 2, 0});
    P.pb({2, 0, 1});
    P.pb({2, 1, 0});
    vector<int> used(n);
    deque<pii> Q;
    int ans = 1e17;
    vector<int> realans;
    for (auto perm : P) {
        fill(used.begin(), used.end(), 0);
        used[strt] = 1;
        Q.clear();
        Q.pb({strt, 0});
        int cnt = C[get<0>(perm)][strt];
        int color = 0;
        vector<int> colors(n);
        colors[strt] = get<0>(perm);
        while (!Q.empty()) {
            v1 = Q[0].first;
            color = Q[0].second;
            Q.pop_front();
            for (auto v2 : graph[v1]) {
                if (used[v2] == 0) {
                    used[v2] = 1;
                    Q.pb({v2, (color + 1) % 3});
                    if (color == 0) {
                        cnt += C[get<1>(perm)][v2];
                        colors[v2] = get<1>(perm);
                    } else if (color == 1) {
                        cnt += C[get<2>(perm)][v2];
                        colors[v2] = get<2>(perm);
                    } else {
                        cnt += C[get<0>(perm)][v2];
                        colors[v2] = get<0>(perm);
                    }
                }
            }
        }
        if (ans > cnt) {
            ans = cnt;
            realans = colors;
        }
    }
    cout << ans << '\n';
    for (auto j : realans) {
        cout << j + 1 << ' ';
    }

}