#include <iostream>
#include <algorithm>
#include <vector>

int t;
std::vector<int> p;

int main() {
    while (std::cin >> t) { p.push_back(t); } p[0]++;
    std::sort(p.begin(), p.end());
    for (int i = 0; ; i++) { if (p[i] != i + 1) { std::cout << i + 1; break; } }
    return 0;
}