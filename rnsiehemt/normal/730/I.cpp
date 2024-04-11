#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, p, s, c[3001][3001], b[3001][3001];
pair<pair<int, int>, int> v[3000];

int f(int i, int r) {
    if (r < 0) return -1e9;
    if (c[i][r]) return c[i][r] - 1;
    if (i == p + s - r) {
        vector<int> w;
        for (int j = i; j < n; ++j) w.push_back(v[j].first.second);
        sort(w.begin(), w.end(), greater<int>());
        int t = 0;
        for (int j = 0; j < min(r, (int)w.size()); ++j) t += w[j];
        return (c[i][r] = t + 1) - 1;
    }
    int m1 = f(i + 1, r - 1) + v[i].first.second, m2 = f(i + 1, r) + v[i].first.first;
    b[i][r] = -1;
    c[i][r] = m1 + 1;
    if (m2 > m1) b[i][r] = 1, c[i][r] = m2 + 1;
    return c[i][r] - 1;
}

int main() {
    cin >> n >> p >> s;
    for (int i = 0; i < n; ++i) cin >> v[i].first.first, v[i].second = i + 1;
    for (int i = 0; i < n; ++i) cin >> v[i].first.second;
    sort(v, v + n, greater<pair<pair<int, int>, int>>());
    cout << f(0, s) << '\n';
    vector<int> w;
    int i = 0, r = s;
    for (; ; ++i) {
        if (b[i][r] > 0) cout << v[i].second << ' ';
        else if (b[i][r] < 0) --r, w.push_back(v[i].second);
        else break;
    }
    cout << '\n';
    for (int i = 0; i < w.size(); ++i) cout << w[i] << ' ';
    {
        vector<pair<int, int>> w;
        for (int j = i; j < n; ++j) w.emplace_back(v[j].first.second, v[j].second);
        sort(w.begin(), w.end(), greater<pair<int, int>>());
        for (int j = 0; j < min(r, (int)w.size()); ++j) cout << w[j].second << ' ';
    }
    cout << '\n';
    return 0;
}