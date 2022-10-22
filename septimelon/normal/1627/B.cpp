#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 4e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(643896);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void sub(ll& a, ll b) {
    add(a, MOD - b);
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll to_deg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans = to_deg(x, d / 2);
    mul(ans, ans);
    if (d & 1) {
        mul(ans, x);
    }
    return ans;
}

struct Point {
    int x, y;

    bool operator<(const Point& p) const {
        if (x != p.x) {
            return x < p.x;
        }
        return y < p.y;
    }
};

int dist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<Point> corn;
    for (int i = 0; i < n; i += max(1, n - 1)) {
        for (int j = 0; j < m; j += max(1, m - 1)) {
            corn.emplace_back(i, j);
        }
    }

    vector<pair<int, Point>> v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int maxd = 0;
            for (Point p : corn) {
                maxd = max(maxd, dist(p, { i, j }));
            }
            v.push_back({ maxd, {i, j} });
        }
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    while (!v.empty()) {
        cout << v.back().first << " ";
        v.pop_back();
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}