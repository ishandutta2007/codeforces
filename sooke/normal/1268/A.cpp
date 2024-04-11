#include <bits/stdc++.h>

int n, m;
std::string s, t, ans;

bool check() {
    for (int i = 0; i < n; i++) {
        if (s[i] > ans[i]) { return false; }
        if (s[i] < ans[i]) { return true; }
    }
    return true;
}

void dfs(int i) {
    if (t[i] == '9') {
        dfs(i - 1); t[i] = '0';
    } else {
        t[i]++;
    }
}

int main() {
    std::cin >> n >> m >> s;
    for (int i = 0; i < m; i++) { t += s[i]; }
    while (true) {
        ans += t;
        if (ans.size() > n) { break; }
    }
    ans.resize(n);
    if (check()) {
        std::cout << n << std::endl << ans << std::endl;
        return 0;
    }
    t = ans = "";
    for (int i = 0; i < m; i++) { t += s[i]; }
    dfs(m - 1);
    while (true) {
        ans += t;
        if (ans.size() > n) { break; }
    }
    ans.resize(n);
    if (check()) {
        std::cout << n << std::endl << ans << std::endl;
        return 0;
    }
    return 0;
}