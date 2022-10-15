#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

int n;
std::string s, t;
std::vector<int> a, b;
std::vector<char> c, d;

void get(std::string s, std::vector<int> &a, std::vector<char> &c) {
    a.clear(); c.clear(); a.push_back(0); c.push_back('#');
    for (int i = 0; i < (int) s.size(); i++) {
        if (c.back() != s[i]) {
            a.push_back(1);
            c.push_back(s[i]);
        } else { a[a.size() - 1]++; }
    }
}

bool check() {
    if (a.size() != b.size()) { return false; }
    for (int i = 0; i < (int) a.size(); i++) {
        if (c[i] != d[i]) { return false; }
        if (a[i] > b[i]) { return false; }
    }
    return true;
}

int main() {
    for (std::cin >> n; n; n--) {
        std::cin >> s >> t; get(s, a, c); get(t, b, d);
        printf("%s\n", check() ? "YES" : "NO");
    }
    return 0;
}