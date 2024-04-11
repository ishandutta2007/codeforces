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

int n, m;
std::string str;

int main() {
    std::cin >> n >> str; m = (n - 11) / 2;
    for (int i = 0, x = 0, y = 0; i < n; i++) {
        if (str[i] == '8') {
            if (x < m) { x++; str[i] = '-'; }
        } else {
            if (y < m) { y++; str[i] = '-'; }
        }
        if (str[i] != '-') {
            if (str[i] == '8') {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
            break;
        }
    }
    return 0;
}