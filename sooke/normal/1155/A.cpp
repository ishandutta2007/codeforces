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
std::string str;

int main() {
    std::cin >> n >> str;
    for (int i = 1; i < n; i++) {
        if (str[i - 1] > str[i]) {
            std::cout << "YES\n" << i << " " << i + 1;
            return 0;
        }
    }
    std::cout << "NO\n";
    return 0;
}