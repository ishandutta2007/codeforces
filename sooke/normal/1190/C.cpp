#include <bits/stdc++.h>

int n, m;
std::string str;

bool check1(char c) {
    int l = 1e9, r = -1e9;
    for (int i = 0; i < n; i++) {
        if (str[i] == c) {
            if (l == 1e9) { l = i; }
            r = i;
        }
    }
    return r - l + 1 <= m;
}

bool check2(char c) {
    int l = 1e9, r = -1e9;
    for (int i = 0; i < n; i++) {
        if (str[i] == c) {
            if (l == 1e9) { l = i; }
            r = i;
        }
    }
    return r - l + 1 > m + 1;
}

bool check3(char c) {
    for (int i = 0, j = 0; i < n; i++) {
        if (str[i] == c) {
            j++;
            if (j >= m) { return true; }
        } else { j = 0; }
    }
    return false;
}

int main() {
    std::cin >> n >> m >> str;
    if (check1('0') || check1('1')) { printf("tokitsukaze\n"); }
    else if (!check2('0') && !check2('1') && !check3('0') && !check3('1')) { printf("quailty\n"); }
    else { printf("once again\n"); }
    return 0;
}