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

int query(std::vector<int> u) {
    int num; std::string s; std::cout << "next";
    for (int i = 0; i < (int) u.size(); i++) { std::cout << " " << u[i]; }
    std::cout << std::endl; std::cout.flush(); std::cin >> num;
    for (int i = 0; i < num; i++) { std::cin >> s; }
    return num;
}

std::vector<int> u;

int main() {
    std::ios::sync_with_stdio(false);
    while (1) {
        u.clear(); u.push_back(0); u.push_back(1); query(u);
        u.clear(); u.push_back(1);
        if (query(u) == 2) break;
    }
    while (1) {
        u.clear();
        for (int i = 0; i <= 9; i++) { u.push_back(i); }
        if (query(u) == 1) break;
    }
    std::cout << "done" << std::endl; std::cout.flush();
    return 0;
} //