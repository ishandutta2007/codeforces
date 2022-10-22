#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
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

const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld INFLD = 1e20;
const ll INFL = 1e17;
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

vector<vector<ll>> minc(101, vector<ll>(20001, INF));

struct XYData {
    ll v1, v2;
    ll c1, c2;
    ll val;
};

void Solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> vtoc;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (vtoc.count(a[i]) == 0) {
            vtoc[a[i]] = 0;
        }
        ++vtoc[a[i]];
    }
    set<pair<int, int>> bp;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        bp.insert({ x, y });
        bp.insert({ y, x });
    }

    vector<int> lastdv(n + 1, -1);
    vector<int> diffd;
    map<int, int> prevsd;
    for (auto it = vtoc.begin(); it != vtoc.end(); ++it) {
        prevsd[it->first] = lastdv[it->second];
        if (lastdv[it->second] == -1) {
            diffd.push_back(it->second);
        }
        lastdv[it->second] = it->first;
    }
    
    vector<XYData> added;
    set<pair<int, int>> included;
    auto comp = [&](int li, int ri) {
        return added[li].val < added[ri].val;
    };
    priority_queue<int, vector<int>, decltype(comp)> que{ comp };
    for (int i = 0; i < diffd.size(); ++i) {
        int di = diffd[i];
        for (int j = i + 1; j < diffd.size(); ++j) {
            int dj = diffd[j];
            added.push_back({ lastdv[di], lastdv[dj], di, dj, (ll)(lastdv[di] + lastdv[dj]) * (ll)(di + dj) });
            included.insert({ lastdv[di], lastdv[dj] });
            que.push(added.size() - 1);
        }
        if (prevsd[lastdv[di]] != -1) {
            added.push_back({ lastdv[di], prevsd[lastdv[di]], di, di, (ll)(lastdv[di] + prevsd[lastdv[di]]) * (ll)(di + di) });
            included.insert({ lastdv[di], prevsd[lastdv[di]] });
            que.push(added.size() - 1);
        }
    }

    while (true) {
        int cixy = que.top();
        que.pop();
        XYData data = added[cixy];
        //cout << data.v1 << " " << data.v2 << " " << data.c1 << " " << data.c2 << " " << data.val << endl;
        if (bp.count(pair<int, int>(data.v1, data.v2)) == 0) {
            cout << data.val << "\n";
            return;
        }
        int p1 = prevsd[data.v1], p2 = prevsd[data.v2];
        if (p1 != data.v2 && included.count({ p1, data.v2 }) == 0 && p1 != -1) {
            added.push_back({ p1, data.v2, data.c1, data.c2, (ll)(p1 + data.v2) * (ll)(data.c1 + data.c2) });
            included.insert({ p1, data.v2 });
            que.push(added.size() - 1);
        }
        if (p2 != data.v1 && included.count({ data.v1, p2 }) == 0 && p2 != -1) {
            added.push_back({ data.v1, p2, data.c1, data.c2, (ll)(p2 + data.v1) * (ll)(data.c1 + data.c2) });
            included.insert({ data.v1, p2 });
            que.push(added.size() - 1);
        }
    }
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