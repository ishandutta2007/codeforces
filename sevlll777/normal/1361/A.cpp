#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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

using namespace std;
#define pb push_back
// #define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> G;
    vector<vector<int>> S(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G.pb({a, b});
        S[a].pb(b);
        S[b].pb(a);
    }
    vector<int> T(n);
    for (int i = 0; i < n; i++) cin >> T[i];
    bool ok = true;
    for (auto p : G) {
        if (T[p.first] == T[p.second]) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "-1\n";
        return 0;
    }
    vector<pair<int, int>> H;
    for (int i = 0; i < n; i++) {
        H.pb({T[i], i});
    }
    sort(H.begin(), H.end());
    vector<int> P;
    for (auto y : H) P.pb(y.second);
    vector<bool> used(n, false);

    for (auto num : P) {
        set<int> O;
        for (auto u : S[num]) {
            if (used[u]) {
                O.insert(T[u]);
            }
        }
        int dud = 1;
        while (O.find(dud) != O.end()) dud++;
        if (T[num] != dud) {
            ok = false;
            break;
        }
        used[num] = true;
    }

    if (!ok) {
        cout << "-1\n";
    } else {
        for (auto num : P) cout << num+1 << '\n';
    }
}