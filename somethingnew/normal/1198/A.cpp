#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    sort(all(a));
    l *= 8;
    int K = 1 << (min(l / n, 30));
    vector<pair<int, int>> b;
    for (auto i : a) {
        if (!b.empty()) {
            if (i == b.back().first) {
                b.back().second++;
            } else {
                b.push_back({i, 1});
            }
        } else {
            b.push_back({i, 1});
        }
    }
    int t = b.size() - K;
    if (t <= 0) {
        cout << 0;
        return 0;
    }
    vector<int> pref(b.size() + 1), suff(b.size() + 1);
    for (int i = 0; i < b.size(); ++i) {
        pref[i + 1] = pref[i] + b[i].second;
        suff[i + 1] = suff[i] + b[b.size() - i - 1].second;
    }
    int res = 1e9;
    for (int i = 0; i <= t; ++i) {
        res = min(res, pref[i] + suff[t - i]);
    }
    cout << res;
}