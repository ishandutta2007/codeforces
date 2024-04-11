#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int n, maxX = INT_MIN, maxY = INT_MIN, maxDiag = INT_MIN, minX = INT_MAX, minY = INT_MAX, minDiag = INT_MAX;
pair<int, int> pt[300005];

pair<int, int> ok(int r) {
    vector<pair<int, int>> centers;
    centers.emplace_back(maxX - r, maxY - r);
    centers.emplace_back(minX + r, minY + r);
    centers.emplace_back(maxX - r, minY + r);
    centers.emplace_back(minX + r, maxY - r);
    centers.emplace_back(maxX - r, maxX - maxDiag);
    centers.emplace_back(minX + r, minX - minDiag);
    centers.emplace_back(maxY + minDiag, maxY - r);
    centers.emplace_back(minY + maxDiag, minY + r);
    for (auto &p : centers) {
        if ((p.first == 0 && p.second == 0) || p.first < 0 || p.second < 0)
            continue;
        bool flag = true;
        for (int i=0; i<n; i++)
            if (abs(pt[i].first - p.first) + abs(pt[i].second - p.second) > r
            && !(pt[i].first >= p.first && pt[i].second >= p.second && pt[i].first - p.first <= r && pt[i].second - p.second <= r)
            && !(pt[i].first <= p.first && pt[i].second <= p.second && p.first - pt[i].first <= r && p.second - pt[i].second <= r)) {
                flag = false;
                break;
            }
        if (flag)
            return p;
    }
    return {-1, -1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        pt[i] = {0, 0};
        for (char c : s) {
            if (c == 'B') pt[i].first++;
            else pt[i].second++;
        }
        maxX = max(maxX, pt[i].first);
        maxY = max(maxY, pt[i].second);
        maxDiag = max(maxDiag, pt[i].first - pt[i].second);
        minX = min(minX, pt[i].first);
        minY = min(minY, pt[i].second);
        minDiag = min(minDiag, pt[i].first - pt[i].second);
    }

    int l = 0, r = 1e6 + 5;
    while (l < r) {
        int m = (l + r) / 2;
        if (ok(m).first != -1)
            r = m;
        else
            l = m + 1;
    }

    auto ret = ok(l);
    cout << l << "\n" << string(ret.first, 'B') << string(ret.second, 'N') << "\n";

    return 0;
}