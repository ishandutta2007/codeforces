#include <bits/stdc++.h>

int n;
std::string s, t;
std::vector<std::pair<int, int>> ans;
std::set<int> sa, sb, ta, tb;

bool check() {
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            x++;
            if (t[i] == 'b') {
                sa.insert(i); tb.insert(i);
            }
        } else {
            y++;
            if (t[i] == 'a') {
                sb.insert(i); ta.insert(i);
            }
        }
        if (t[i] == 'a') {
            x++;
        } else {
            y++;
        }
    }
    if (x % 2 == 1 && y % 2 == 1) { return false; }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            if (t[i] == 'b') {
                sa.erase(i); tb.erase(i);
            }
        } else {
            if (t[i] == 'a') {
                sb.erase(i); ta.erase(i);
            }
        }
        if (s[i] != t[i]) {
            if (s[i] == 'a') {
                if (!tb.empty()) {
                    int j = *tb.begin();
                    tb.erase(j); sa.erase(j);
                    ans.push_back({i, j}); std::swap(s[i], t[j]);
                } else if (!sa.empty()) {
                    int j = *sa.begin();
                    sa.erase(j); tb.erase(j);
                    ans.push_back({j, i}); std::swap(s[j], t[i]);
                }
            } else {
                if (!ta.empty()) {
                    int j = *ta.begin();
                    ta.erase(j); sb.erase(j);
                    ans.push_back({i, j}); std::swap(s[i], t[j]);
                } else if (!sb.empty()) {
                    int j = *sb.begin();
                    sb.erase(j); ta.erase(j);
                    ans.push_back({j, i}); std::swap(s[j], t[i]);
                }
            }
            if (s[i] == t[i]) { continue; }
            ans.push_back({i, i}); std::swap(s[i], t[i]);
            if (s[i] == 'a') {
                if (!tb.empty()) {
                    int j = *tb.begin();
                    tb.erase(j); sa.erase(j);
                    ans.push_back({i, j}); std::swap(s[i], t[j]);
                } else if (!sa.empty()) {
                    int j = *sa.begin();
                    sa.erase(j); tb.erase(j);
                    ans.push_back({j, i}); std::swap(s[j], t[i]);
                }
            } else {
                if (!ta.empty()) {
                    int j = *ta.begin();
                    ta.erase(j); sb.erase(j);
                    ans.push_back({i, j}); std::swap(s[i], t[j]);
                } else if (!sb.empty()) {
                    int j = *sb.begin();
                    sb.erase(j); ta.erase(j);
                    ans.push_back({j, i}); std::swap(s[j], t[i]);
                }
            }
        }
    } return true;
}

int main() {
    std::cin >> n >> s >> t;
    if (check()) {
        printf("%u\n", ans.size());
        for (auto i : ans) {
            printf("%d %d\n", i.first + 1, i.second + 1);
        }
    } else {
        printf("-1\n");
    }
    return 0;
}