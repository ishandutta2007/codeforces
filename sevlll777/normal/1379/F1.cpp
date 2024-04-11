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
#include <bitset>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    int qq = q;
    vector<int> MIN(m + 1, -1e9), MAX(m + 1, 1e9);
    vector<vector<pair<int, int>>> maxim(m + 1), minim(m + 1);
    vector<vector<int>> minim0(m + 1), maxim0(m + 1);
    int TIME = 0;
    while (q--) {
        int i, j;
        cin >> i >> j;
        int b = (j + 1) / 2;
        if (i % 2 == 1) {
            MAX[b] = min(MAX[b], i / 2);
            maxim[b].pb({TIME, i / 2});
        } else {
            MIN[b] = max(MIN[b], i / 2);
            minim[b].pb({TIME, i / 2});
        }
        /*
        int mim = 1e9;
        bool ok = true;
        for (int g = 1; g <= m; g++) {
            mim = min(mim, MAX[g]);
            if (mim < MIN[g]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            q++;
            while (q--) {
                cout << "NO\n";
            }
            exit(0);
        }
         */
        TIME++;
    }
    for (int t = 1; t <= m; t++) {
        for (int i = 1; i < maxim[t].size(); i++) {
            maxim[t][i].second = min(maxim[t][i - 1].second, maxim[t][i].second);
        }
        for (int i = 1; i < minim[t].size(); i++) {
            minim[t][i].second = max(minim[t][i - 1].second, minim[t][i].second);
        }
        for (int i = 0; i < maxim[t].size(); i++) maxim0[t].pb(maxim[t][i].first);
        for (int i = 0; i < minim[t].size(); i++) minim0[t].pb(minim[t][i].first);
    }
    int l = -1;
    int r = qq;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector<int> MIIN(m + 1, -1e9), MAAX(m + 1, 1e9);
        for (int g = 1; g <= m; g++) {
            if (!minim[g].empty() && minim[g][0].first <= mid) {
                int TTT = (int) (upper_bound(minim0[g].begin(), minim0[g].end(), mid) - minim0[g].begin());
                MIIN[g] = minim[g][TTT-1].second;
            }
            if (!maxim[g].empty() && maxim[g][0].first <= mid) {
                int TTT = (int) (upper_bound(maxim0[g].begin(), maxim0[g].end(), mid) - maxim0[g].begin());
                MAAX[g] = maxim[g][TTT-1].second;
            }
        }
        int mim = 1e9;
        bool ok = true;
        for (int g = 1; g <= m; g++) {
            mim = min(mim, MAAX[g]);
            if (mim < MIIN[g] || MIIN[g]>MAAX[g]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            l = mid;
        } else {
            r = mid;
        }
    }
    for (int _ = 0; _ < l + 1; _++) cout << "YES\n";
    for (int _ = l + 1; _ < qq; _++) cout << "NO\n";
}