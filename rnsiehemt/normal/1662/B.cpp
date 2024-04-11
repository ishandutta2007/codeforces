#include <bits/stdc++.h>
using namespace std;

vector<int> cnt(string s) {
    vector<int> c(26);
    for (char ch : s) {
        c[ch - 'A']++;
    }
    return c;
}

bool check(vector<int> &xcnt, vector<int> &ycnt, vector<int> &zcnt, int i, vector<int> &xy) {
    if (xcnt[i] >= zcnt[i] && ycnt[i] >= zcnt[i] && min(xcnt[i], ycnt[i]) > 0) {
        xcnt[i]--;
        ycnt[i]--;
        xy.push_back(i);
        return true;
    }
    return false;
}

void pair1(vector<int> &xy, vector<int> &z, vector<pair<int, int>> &ans) {
    while (!xy.empty() && !z.empty()) {
        ans.emplace_back(xy.back(), z.back());
        xy.pop_back();
        z.pop_back();
    }
}

bool pair2(vector<int> &x, vector<int> &y, vector<int> &z, vector<pair<int, int>> &ans) {
    if (x.size() >= z.size() && y.size() >= z.size() && !x.empty() && !y.empty()) {
        ans.emplace_back(x.back(), y.back());
        x.pop_back();
        y.pop_back();
        return true;
    }
    return false;
}

void remain(vector<int> &v, vector<pair<int, int>> &ans) {
    while (!v.empty()) {
        ans.emplace_back(v.back(), 25);
        v.pop_back();
    }
}

int main() {
    string Xs, Ys, Zs;
    cin >> Xs >> Ys >> Zs;
    auto xcnt = cnt(Xs);
    auto ycnt = cnt(Ys);
    auto zcnt = cnt(Zs);
    vector<int> xy, xz, yz;
    vector<int> x, y, z;
    for (int i = 0; i < 26; i++) {
        while (check(xcnt, ycnt, zcnt, i, xy) ||
                check(xcnt, zcnt, ycnt, i, xz) ||
                check(ycnt, zcnt, xcnt, i, yz));
        while (xcnt[i]--) {
            x.push_back(i);
        }
        while (ycnt[i]--) {
            y.push_back(i);
        }
        while (zcnt[i]--) {
            z.push_back(i);
        }
    }
    vector<pair<int, int>> ans;
    pair1(xy, z, ans);
    pair1(xz, y, ans);
    pair1(yz, x, ans);
    while (!xy.empty() && !xz.empty() && !yz.empty()) {
        ans.emplace_back(xy.back(), xz.back());
        ans.emplace_back(xy.back(), yz.back());
        xy.pop_back();
        xz.pop_back();
        yz.pop_back();
    }
    while (pair2(x, y, z, ans) ||
            pair2(x, z, y, ans) ||
            pair2(y, z, x, ans));
    remain(xy, ans);
    remain(xz, ans);
    remain(yz, ans);
    remain(x, ans);
    remain(y, ans);
    remain(z, ans);

    cout << ans.size() << "\n";
    for (auto [i, j] : ans) {
        cout << (char) (i + 'A') << (char) (j + 'A') << "\n";
    }
}