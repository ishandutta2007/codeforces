#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, k, a[N];
long long lst = -1e18, ans[N];
std::set<int> set, ot;
std::vector<std::pair<long long, int>> vec;
std::priority_queue<std::pair<long long, int>> que;

int main() {
    n = read(); k = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); que.push({-a[i], i});
    }
    while (true) {
        if (que.empty()) { break; }
        vec.clear();
        vec.push_back(que.top()); que.pop();
        while (!que.empty()) {
            if (que.top().first == vec[0].first) {
                vec.push_back(que.top()); que.pop();
            } else {
                break;
            }
        }
        int pos = vec.size(), nxt = -1;
        long long now = -vec[0].first;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].second < 998244353) { pos = i; break; }
        }
        for (int i = 0; i < pos; i++) { ot.erase(vec[i].second - 998244353); }
        for (int i = pos; i < vec.size(); i++) { set.insert(vec[i].second); }
        for (int i = 0; i < pos; i++) {
            int u = vec[i].second - 998244353;
            auto it = set.lower_bound(u);
            if (it == set.end()) { continue; }
            int v = *it;
            if (ot.lower_bound(v) == ot.begin()) {
                if (nxt == -1 || v < nxt) { nxt = v; }
            }
        }
        for (int i = pos; i < vec.size(); i++) {
            int u = vec[i].second;
            if (ot.lower_bound(u) == ot.begin()) {
                if (nxt == -1 || u < nxt) { nxt = u; }
            }
        }
        if (nxt != -1) {
            ans[nxt] = std::max(now, lst) + k;
            lst = std::max(lst, ans[nxt]);
            set.erase(nxt); que.push({-ans[nxt], nxt + 998244353}); ot.insert(nxt);
        }
    }
    for (int i = 0; i < n; i++) { printf("%I64d ", ans[i]); }
    return 0;
}