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
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> P;
    for (int i = 0; i < n; i++) {
        vector<int> heh(m);
        for (int j = 0; j < m; j++) cin >> heh[j];
        P.pb(heh);
    }
    int left = -1;
    int right = 1e9 + 2;
    vector<int> po2 = {1};
    for (int i = 0; i < 10; i++) po2.pb(po2.back() * 2);
    vector<pii> keka;
    for (int x = 0; x < po2[m]; x++) {
        for (int y = x; y < po2[m]; y++) {
            if ((x & y) == 0) {
                keka.pb({x, y});
            }
        }
    }
    map<int, pii> ans;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        vector<int> kek(po2[m]);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (P[i][j] < mid) {
                    cnt += po2[m - j - 1];
                }
            }
            kek[cnt] = i + 1;
        }
        int p1 = 0, p2 = 0;
        bool f = false;
        for (auto p : keka) {
            if (kek[p.first] > 0 && kek[p.second] > 0) {
                f = true;
                p1 = kek[p.first];
                p2 = kek[p.second];
                break;
            }
        }
        if (f) {
            left = mid;
            ans[left] = {p1, p2};
        } else {
            right = mid;
        }
    }
    cout << ans[left].first << ' ' << ans[left].second;
}