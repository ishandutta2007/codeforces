#include <cstdio>
#include <iostream>

int n, x, y;
std::string str;

int main() {
    std::cin >> str; n = str.size();
    for (int i = 0; i < n; i++) {
        if (str[i] & 15) {
            printf("1 %d\n", x << 1 | 1); x++;
            if (x == 2) { x = 0; }
        } else {
            y++; printf("3 %d\n", y);
            if (y == 4) { y = 0; }
        }
    }
    return 0;
}