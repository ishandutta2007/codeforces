#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

const int INF = 1000000009;

int todeg(int x, int deg) {
    if (deg == 0) {
        return 1;
    }
    int ans = todeg(x, deg / 2);
    ans *= ans;
    if (deg % 2 == 1) {
        ans *= x;
    }
    return ans;
}

void fatt(int cv, int ind, vector<int>& ans, set<int>& inc, vector<int>& els, vector<int>& deg) {
    if (cv != 1 && inc.count(cv) == 0) {
        ans.push_back(cv);
        inc.insert(cv);
    }
    if (ind == els.size()) {
        return;
    }
    for (int cd = 0; cd <= deg[ind]; ++cd) {
        fatt(cv * todeg(els[ind], cd), ind + 1, ans, inc, els, deg);
    }
}

void att(int cv, int ind, vector<int>& ans, set<int>& inc, vector<int>& els, vector<int>& deg) {
    if (cv != 1 && inc.count(cv) == 0) {
        ans.push_back(cv);
        inc.insert(cv);
    }
    if (ind == els.size()) {
        return;
    }
    for (int cd = 1; cd <= deg[ind]; ++cd) {
        fatt(cv * todeg(els[ind], cd), ind + 1, ans, inc, els, deg);
    }
    att(cv, ind + 1, ans, inc, els, deg);
}

void solve() {
    int n;
    cin >> n;

    vector<int> els, deg;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            els.push_back(i);
            deg.push_back(0);
            while (n % i == 0) {
                n /= i;
                ++deg.back();
            }
        }
    }
    if (n > 1) {
        els.push_back(n);
        deg.push_back(1);
    }

    vector<int> ans;
    set<int> inc;
    if (els.size() == 2) {
        if (deg[0] == 1 && deg[1] == 1) {
            cout << els[0] << " " << els[1] << " " << els[0] * els[1] << "\n";
            cout << "1\n";
            return;
        }
        ans.push_back(todeg(els[0], deg[0]) * todeg(els[1], deg[1]));
        for (int i = 1; i <= deg[0]; ++i) {
            ans.push_back(todeg(els[0], i));
        }
        for (int i = 1; i <= deg[0]; ++i) {
            for (int j = 1; j <= deg[1]; ++j) {
                ans.push_back(todeg(els[0], i) * todeg(els[1], j));
            }
        }
        for (int j = 1; j <= deg[1]; ++j) {
            ans.push_back(todeg(els[1], j));
        }
    }
    else {
        ans.push_back(els[0] * els.back());
        inc.insert(ans[0]);
        att(1, 0, ans, inc, els, deg);
    }

    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) {
        if (ans[i] != ans[0]) {
            cout << " " << ans[i];
        }
    }
    cout << "\n0\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }

    return 0;
}