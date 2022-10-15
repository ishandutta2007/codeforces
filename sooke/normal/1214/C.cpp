#include <bits/stdc++.h>

int n, p, q;
char c;
std::string s, t;

int find(std::string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            cnt++;
        } else {
            cnt--;
            if (cnt < 0) { return i; }
        }
    }
    if (cnt != 0) { return s.size(); }
    return -1;
}

int main() {
    std::cin >> n >> s;
    p = find(s);
    if (p == -1) {
        std::cout << "YES\n";
        return 0;
    }
    if (p == s.size()) {
        std::cout << "NO\n";
        return 0;
    }
    t = s;
    c = t[p];
    t.erase(t.begin() + p);
    q = find(t);
    t.insert(t.begin() + q, c);
    p = find(t);
    if (p == -1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}