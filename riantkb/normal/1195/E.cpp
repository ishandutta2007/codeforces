#include<bits/stdc++.h>
using namespace std;

vector<int> slide_min(const vector<int> &v, int k) {
    deque<int> deq;
    vector<int> ret;
    for(int i = 0; i < (int)v.size(); i++) {
        while (!deq.empty() && v[deq.back()] >= v[i]) deq.pop_back();
        deq.push_back(i);
        if (i - k + 1 >= 0) {
            ret.emplace_back(v[deq.front()]);
            if (deq.front() == i - k + 1) deq.pop_front();
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int h, w, a, b;
    long long g, x, y, z;
    cin >> h >> w >> a >> b >> g >> x >> y >> z;
    vector<vector<int>> s(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            s[i][j] = g;
            g = (g * x + y) % z;
        }
        s[i] = slide_min(s[i], b);
    }
    long long ans = 0;
    for (int i = 0; i < w - b + 1; ++i) {
        vector<int> s2(h);
        for (int j = 0; j < h; ++j) {
            s2[j] = s[j][i];
        }
        s2 = slide_min(s2, a);
        for (auto& j : s2) {
            ans += j;
        }
    }
    cout << ans << '\n';
    return 0;
}