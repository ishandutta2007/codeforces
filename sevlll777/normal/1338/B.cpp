#define __GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define dbl long double
#define str string
using namespace std;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> gr(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    vector<int> lists, nonlists;
    for (int v = 0; v < n; v++) {
        if ((int) gr[v].size() == 1) {
            lists.pb(v);
        } else {
            nonlists.pb(v);
        }
    }
    int ansmin = 0, ansmax = 0;
    vector<int> depth(n);
    depth[0] = 0;
    vector<bool> used(n, false);
    used[0] = true;
    deque<int> q = {0};
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (auto uu : gr[u]) {
            if (!used[uu]) {
                used[uu] = true;
                q.pb(uu);
                depth[uu] = 1 + depth[u];
            }
        }
    }
    set<int> fath;
    map<int, int> lil;
    for (auto l : lists) {
        fath.insert(gr[l][0]);
        lil[gr[l][0]] = l;
    }
    int c0 = 0, c1 = 0;
    for (auto l : lil) {
        if (depth[l.second] % 2) {
            c0++;
        } else {
            c1++;
        }
    }
    if (c0 == 0 || c1 == 0) {
        ansmin = 1;
    } else {
        ansmin = 3;
    }
    ansmax = n - 1 - ((int) lists.size() - (int) fath.size());
    cout << ansmin << ' ' << ansmax;
}