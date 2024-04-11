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

int n, m, k;
std::string str;

int main() {
    std::cin >> n >> str; str = " " + str;
    if (str[1] == ')' || str[n] == '(' || (n & 1)) { printf(":(\n"); return 0; }
    str[1] = '('; str[n] = ')';
    for (int i = 2; i < n; i++) {
        if (str[i] == '(') { k--; }
        else if (str[i] == ')') { k++; }
        else { m++; }
    }
    if ((m - k) & 1) { printf(":(\n"); return 0; }
    k = (m - k) / 2 + k;
    if (k < 0 || k > m) { printf(":(\n"); return 0; }
    for (int i = 2; i < n; i++) {
        if (str[i] == '?') {
            if (k > 0) { k--; str[i] = '('; } else { str[i] = ')'; }
        }
    }
    k = 0;
    for (int i = 1; i <= n; i++) {
        if (str[i] == '(') { k++; } else { k--; }
        if (k == 0 && i < n) { printf(":(\n"); return 0; }
    }
    if (k != 0) { printf(":(\n"); return 0; }
    str.erase(str.begin(), str.begin() + 1);
    std::cout << str << std::endl;
    return 0;
}