#include <bits/stdc++.h>

int n;
std::string str;

void solve(int l, int r) {
    int s = l + 1, t = r - 1;
    if (s < t) {
        if (str[l] == str[r]) {
            str[s] = str[t] = '-';
            solve(s + 1, t - 1);
        } else if (str[l] == str[t]) {
            str[s] = str[r] = '-';
            solve(s + 1, t - 1);
        } else if (str[s] == str[r]) {
            str[l] = str[t] = '-';
            solve(s + 1, t - 1);
        } else if (str[s] == str[t]) {
            str[l] = str[r] = '-';
            solve(s + 1, t - 1);
        }
    } else if (s == t) {
        str[l] = str[r] = '-';
    } else if (s == r) {
        str[r] = '-';
    }
}

int main() {
    std::cin >> str;
    n = str.size();
    solve(0, n - 1);
    for (int i = 0; i < n; i++) {
        if (str[i] != '-') { putchar(str[i]); }
    }
    return 0;
}