#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

int n;

void read() {
    cin >> n;
}

vector<pair<int, int>> solve(int l, int r) {
    if (l == r) return {};
    int m = (l + r) / 2;
    auto L = solve(l, m);
    auto R = solve(m + 1, r);
    vector<pair<int, int>> ans;
   

    for (auto i : L) {
        ans.push_back(i);
    }
    for (auto i : R) {
        ans.push_back(i);
    }
    for (int i = 0; i < (r - l + 1) / 2; ++i) {
        ans.push_back({m - i, m + i + 1});
    }
    return ans;
}

vector<pair<int, int>> ans;

void run() {
    int x = 1;
    while (x * 2 <= n) x *= 2;
    ans = solve(1, x);
    if (x != n) {
        auto have = solve(n - x + 1, n);
        for (auto i : have) {
            ans.push_back(i);
        }
    }
}

void write() {
    cout << ans.size() << "\n";
    //exit(0);
    for (auto i : ans) {
        cout << i.first << " " << i.second << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}