#include <bits/stdc++.h>

int n, k, ans;
std::string str;

int main() {
    std::cin >> n >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            k++;
            if (k == 0) {
                ans++;
            }
        } else {
            k--;
        }
        if (k < 0) {
            ans++;
        }
    }
    printf("%d\n", k == 0 ? ans : -1);
    return 0;
}