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
int a, b, c, t, d, n, m, k, x, r, j2, l, q, i, j, v1, v2, p, y, w, l2, r2, m2, x1, x2, z;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    unmp<int, unmp<int, vector<pii>>> P;
    set<pii> trt;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        P[x][y].pb({z, i + 1});
        trt.insert({x, y});
    }
    unmp<int, vector<pii>> kekx;
    vector<pii > zzz;
    for (auto pr : trt) {
        x = pr.first;
        y = pr.second;
        sort(P[x][y].begin(), P[x][y].end());
        for (int i = 0; i < P[x][y].size() - 1; i += 2) {
            cout << P[x][y][i].second << ' ' << P[x][y][i + 1].second << '\n';
        }
        if (P[x][y].size() % 2 == 1) {
            kekx[x].pb({y, P[x][y][P[x][y].size() - 1].second});
        }
    }
    vector<pii> oth;
    for (auto pr : kekx) {
        zzz = pr.second;
        sort(zzz.begin(), zzz.end());
        for (int i = 0; i < zzz.size() - 1; i += 2) {
            cout << zzz[i].second << ' ' << zzz[i + 1].second << '\n';
        }
        if (zzz.size() % 2 == 1) {
            oth.pb({pr.first, zzz[zzz.size() - 1].second});
        }
    }
    sort(oth.begin(), oth.end());
    for (int i = 0; i < oth.size(); i += 2) {
        cout << oth[i].second << ' ' << oth[i + 1].second << '\n';
    }
    return 0;
}