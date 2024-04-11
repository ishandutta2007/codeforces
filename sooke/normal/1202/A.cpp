#include <bits/stdc++.h>

int T, ans;

std::string s, t;

int solve() {
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int pos;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '1') {
            pos = i; break;
        }
    }
    for (int i = pos; i < s.size(); i++) {
        if (s[i] == '1') {
            return i - pos;
        }
    }
    return 0;
}

int main() {
    for (std::cin >> T; T; T--) {
        std::cin >> s >> t;
        std::cout << solve() << std::endl;
    }
    return 0;
}