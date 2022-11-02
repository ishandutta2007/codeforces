#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, d, k;

void read() {
    cin >> n >> k >> d;
}

vector<int> make(vector<vector<int>> & have) {
    vector<int> ans(n);
    vector<vector<int>> nhave;
    for (auto arr : have) {
        vector<vector<int>> fans;
        for (int i = 0; i < (int)arr.size(); i++) {
            if (i < k) {
                fans.push_back({arr[i]});
            } else {
                fans[i % k].push_back(arr[i]);
            }
        }
        for (int i = 0; i < (int)fans.size(); i++) {
            for (auto j : fans[i]) {
                ans[j] = i;
            }
            nhave.push_back(fans[i]);
        }
    }
    have = nhave;
    return ans;
}

vector<vector<int>> ans;

void run() {
    vector<vector<int>> have(1, vector<int> (n, 0));
    iota(all(have[0]), 0);
    for (int i = 0; i < d; i++) {
        ans.push_back(make(have));
    }
    if (have.size() != n) {
        cout << "-1" << endl;
        exit(0);
    }
}

void write() {
    for (auto i : ans) {
        for (auto j : i) {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}