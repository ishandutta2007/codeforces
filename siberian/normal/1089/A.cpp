#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

vector<pair<int, int>> get30(int x, int y) {
    if (x < 75) return {};
    vector<pair<int, int>> ans;
    for (int i = 0; i < 3; ++i) {
        ans.push_back({25, 0});
        x -= 25;
    }
    if (y >= 23) {
        ans[0].second += 23;
        y -= 23;
        int d = min(x, y);
        ans[0].first += d;
        ans[0].second += d;
        x -= d;
        y -= d;
    }
    for (int i = 1; i < 3; ++i) {
        int dy = min(23, y);
        ans[i].second += dy;
        y -= dy;
    }
    if (x != 0 || y != 0) return {};
    return ans;
}   

vector<pair<int, int>> check31(vector<pair<int, int>> ans, int dx, int x, int y) {
    ans[3].first += dx;
    x -= dx;
    while (ans[3].second - 2 < ans[3].first) {
        --y;
        ++ans[3].second;
    }
    if (y < 0) return {};
    if (x == 0) {
        for (int i = 0; i < 3; ++i) {
            int dy = min(y, 23);
            ans[i].second += dy;
            y -= dy;
        }
        if (y != 0) return {};
        return ans;
    } else {
        ans[0].first += x;
        ans[0].second += ans[0].first - 2;
        y -= ans[0].second;
        if (y < 0) return {};
        for (int i = 1; i < 3; ++i) {
            int dy = min(y, 23);
            ans[i].second += dy;
            y -= dy;
        }
        if (y != 0) return {};
        return ans;
    }
}

vector<pair<int, int>> get31(int x, int y) {
    if (x < 75) return {};
    if (y < 25) return {};
    vector<pair<int, int>> ans;
    for (int i = 0; i < 3; ++i) {
        ans.push_back({25, 0});
        x -= 25;
    }
    ans.push_back({0, 25});
    y -= 25;
    for (int fx = 0; fx <= x; ++fx) {
        auto fans = check31(ans, fx, x, y);
        if (!fans.empty()) {
            swap(fans[0], fans[3]);
            return fans;
        }
    }
    return {};
}

vector<pair<int, int>> get32_lastX(int x, int y) {
    if (x < 25 + 25 + 15) return {};
    if (y < 25 + 25) return {};
    vector<pair<int, int>> ans;
    for (int i = 0; i < 2; ++i) {
        ans.push_back({0, 25});
        y -= 25;
    }
    for (int i = 0; i < 2; ++i) {
        ans.push_back({25, 0});
        x -= 25;
    }
    ans.push_back({15, 0});
    x -= 15;
    if (max(x, y) <= 23) {
        ans[3].second += y;
        ans[0].first += x;
        return ans;
    } else if (x <= y) {
        int dy = 23;
        assert(dy <= y);
        ans[3].second += dy;
        y -= dy;
        int add = min(x, y);
        ans[3].first += add;
        ans[3].second += add;
        x -= add;
        y -= add;
        for (int i = 0; i < 2; ++i) {
            int dx = min(ans[i].second - 2 - ans[i].first, x);
            assert(dx >= 0);
            ans[i].first += dx;
            x -= dx;
        }
        for (int i = 2; i < 5; ++i) {
            int dy = min(ans[i].first - 2 - ans[i].second, y);
            assert(dy >= 0);
            ans[i].second += dy;
            y -= dy;
        }
        //assert(x == 0 && y == 0);
        
        if (x != 0 || y != 0) return {};
        return ans;
    } else {
        int dx = 23;
        assert(dx <= x);
        ans[0].first += dx;
        x -= dx;
        int add = min(x, y);
        ans[0].first += add;
        ans[0].second += add;
        x -= add;
        y -= add;
        assert(x >= 0 && y >= 0);
        /*cout << "ans = " << endl;
        for (auto i : ans) {
            cout << i.first << ":" << i.second << " ";
        }
        cout << endl;*/
        for (int i = 0; i < 2; ++i) {
            int dx = min(ans[i].second - 2 - ans[i].first, x);
            assert(dx >= 0);
            ans[i].first += dx;
            x -= dx;
        }
        for (int i = 2; i < 5; ++i) {
            int dy = min(ans[i].first - 2 - ans[i].second, y);
            assert(dy >= 0);
            ans[i].second += dy;
            y -= dy;
        }
        //assert(x == 0 && y == 0);
        
        if (x != 0 || y != 0) return {};
        return ans;
    }
    assert(false);
    return {};
}

vector<pair<int, int>> get32(int x, int y) {
    return get32_lastX(x, y);
}

void check(int x, int y, int mx) {
    assert(x - y >= 2);
    assert(x >= mx);
    if (x > mx) {
        assert(x == y + 2);
    }
}

pair<int, int> calc(vector<pair<int, int>> ans) {
    pair<int, int> fans = {0, 0};
    for (int x = 0; x < min((int)ans.size(), 4); ++x) {
        auto i = ans[x];
        assert(i.first >= 0 && i.second >= 0);
        if (i.first > i.second) {
            fans.first++;
        } else if (i.second > i.first) {
            fans.second++;
        }
        check(max(i.first, i.second), min(i.first, i.second), 25);
        if (fans.first == 3 || fans.second == 3) return fans;
    }
    if (ans.size() == 5) {
        auto i = ans.back();
        assert(i.first >= 0 && i.second >= 0);
        if (i.first > i.second) {
            fans.first++;
        } else if (i.second > i.first) {
            fans.second++;
        }
        check(max(i.first, i.second), min(i.first, i.second), 15);
    }
    return fans;
}

void check(int x, int y, pair<int, int> fans, vector<pair<int, int>> ans) {
    if (ans.empty()) return;
    //auto have = calc(ans);
    assert(calc(ans) == fans);
    for (auto i : ans) {
        x -= i.first;
        y -= i.second;
    }
    assert(x == 0 && y == 0);
}

void solve() {
    int x, y;
    cin >> x >> y;
    pair<int, int> fans;
    vector<pair<int, int>> ans;
    /*ans = get32(y, x);
    cout << "ans = " << endl;
    for (auto i : ans) {
        cout << i.first << ":" << i.second << " "; 
    }
    cout << endl;
    assert(false);*/
    ans = get30(x, y);
    if (!ans.empty()) {
        fans = {3, 0};
    }
    if (ans.empty()) {
        ans = get31(x, y);
        if (!ans.empty()) {
            fans = {3, 1};
        }
    }
    if (ans.empty()) {
        ans = get32(x, y);
        if (!ans.empty()) {
            fans = {3, 2};
        }
    }
    if (ans.empty()) {
        ans = get32(y, x);
        for (auto& i : ans) {
            swap(i.first, i.second);
        }
        if (!ans.empty()) {
            fans = {2, 3};
        }
    }
    if (ans.empty()) {
        ans = get31(y, x);
        for (auto& i : ans) {
            swap(i.first, i.second);
        }
        if (!ans.empty()) {
            fans = {1, 3};
        }
    }
    if (ans.empty()) {
        ans = get30(y, x);
        for (auto& i : ans) {
            swap(i.first, i.second);
        }
        if (!ans.empty()) {
            fans = {0, 3};
        }
    }
    //cerr << "x = " << x << " y = " << y << endl;
    if (ans.empty()) {
        cout << "Impossible\n";
    } else {
        cout << fans.first << ":" << fans.second << "\n";
        for (auto i : ans){
            cout << i.first << ":" << i.second << " ";
        }
        cout << "\n";
    }
    //cout.flush();
    //check(x, y, fans, ans);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}