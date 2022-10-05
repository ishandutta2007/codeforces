#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "set"
#include "array"
#include "map"
#define all(x) x.begin(), x.end()
using namespace std;
int K = 9;
vector<string> getall(string &s) {
    vector<string> alls(1 << K, string(s.size(), '?'));
    for (int i = 0; i < (1 << K); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            alls[i][j] = s[i^j];
        }
    }
    return alls;
}
vector<int> getall2(vector<int> &a) {
    vector<vector<int>> alls(a.size(), vector<int>(a.size()));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            alls[i][j] = a[i^j];
        }
    }
    vector<int> v0 = alls[0];
    for (auto &i : alls)
        v0 = min(v0, i);
    return v0;
}
void solve() {
    int n;
    cin >> n;
    K = min(n, K);
    string s;
    cin >> s;
    string s2;
    vector<vector<string>> elems(1 << (n - K));
    vector<string> a;
    for (int i = 0; i < elems.size(); ++i) {
        int pl = i * (1 << K);
        string ss = s.substr(pl, 1 << K);
        elems[i] = getall(ss);
        for (const auto& q : elems[i])
            a.push_back(q);
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    map<string, int> ind;
    for (int i = 0; i < a.size(); ++i) {
        ind[a[i]] = i;
    }
    vector<vector<int>> elint(1 << K, vector<int>(1 << (n - K)));
    for (int i = 0; i < elems.size(); ++i) {
        int ind2 = 0;
        for (const auto& q : elems[i]) {
            elint[ind2][i] = ind[q];
            ind2++;
        }
    }
    vector<int> res =getall2(elint[0]);
    for (int i = 1; i < elint.size(); ++i) {
        res = min(res, getall2(elint[i]));
    }
    string ans;
    for (auto i : res)
        ans += a[i];
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}