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
#define str string
using namespace std;
const int M = 1000000007;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int mx = 4 * n * m - 2 * n - 2 * m;
    if (mx < k) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    str fint = "RUD";
    vector <pair<int, str>> cmd, ans;
    if (m > 1) {
        cmd.pb({m - 1, "R"});
        cmd.pb({m - 1, "L"});
    }
    for (int i = 0; i < n - 1; i++) {
        cmd.pb({1, "D"});
        if (m > 1) {
            cmd.pb({m - 1, fint});
            cmd.pb({m - 1, "L"});
        }
    }
    if (n > 1) {
        cmd.pb({n - 1, "U"});
    }
    int sum = 0;
    for (int i = 0; i < (int) cmd.size(); i++) {
        int sz = (int) cmd[i].second.size();
        if (sum + cmd[i].first * sz < k) {
            sum += cmd[i].first * sz;
            ans.pb(cmd[i]);
        } else {
            int c = k - sum;
            if (c > 0) {
                if (c < sz) {
                    str r = "";
                    for (int p = 0; p < c; p++) r += cmd[i].second[p];
                    ans.pb({1, r});
                } else {
                    if (c % sz == 0) {
                        ans.pb({c / sz, cmd[i].second});
                    } else {
                        ans.pb({c / sz, cmd[i].second});
                        c %= sz;
                        str r = "";
                        for (int p = 0; p < c; p++) r += cmd[i].second[p];
                        ans.pb({1, r});
                    }
                }
            }
            break;
        }
    }
    cout << ans.size() << '\n';
    for (auto j : ans) {
        cout << j.first << ' ' << j.second << '\n';
    }
}