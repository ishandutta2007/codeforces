#include <bits/stdc++.h>

int n;
bool used[10];

std::string str;

int main() {
    std::cin >> n >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'L') {
            for (int j = 0; j < 10; j++) {
                if (!used[j]) {
                    used[j] = true; break;
                }
            }
        } else if (str[i] == 'R') {
            for (int j = 9; j >= 0; j--) {
                if (!used[j]) {
                    used[j] = true; break;
                }
            }
        } else { used[str[i] & 15] = false; }
    }
    for (int i = 0; i < 10; i++) { std::cout << used[i]; }
    return 0;
}