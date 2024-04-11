#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int n, cnt;
std::string s;

int main() {
    std::cin >> n >> s;
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == 'x' && s[i + 1] == 'x' && s[i + 2] == 'x') { cnt++; }
    }
    std::cout << cnt << std::endl;
}

//././././././as./f./w.3/r./fs.d/.a