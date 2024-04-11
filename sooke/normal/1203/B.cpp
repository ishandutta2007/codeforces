#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n;

std::vector<int> a;

bool change() {
    std::vector<int> b;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i += 2) {
        if (a[i] != a[i + 1]) { return false; }
        b.push_back(a[i]);
    } a = b;
    return true;
}

bool check() {
    if (!change()) { return false; }
    int x = a[0] * a.back();
    for (int i = 0, j = a.size() - 1; i < j; i++, j--) {
        if (x != a[i] * a[j]) { return false; }
    } return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); a.resize(n * 4);
        for (int i = 0; i < a.size(); i++) { a[i] = read(); }
        printf("%s\n", check() ? "YES" : "NO");
    }
    return 0;
}