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
std::string s;

int main() {
    std::cin >> n >> s;
    std::sort(s.begin(), s.end());
    std::cout << s << std::endl;
    return 0;
}///