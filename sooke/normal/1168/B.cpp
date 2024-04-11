#include <iostream>

int n;
long long ans;
std::string str;

int main() {
    std::cin >> str; n = str.size();
    for (int i = 0; i < n; i++) {
        for (int j = i, k; j <= n; j++) {
            for (k = 1; j - k - k >= i && (str[j] != str[j - k] || str[j] != str[j - k - k]); k++);
            if (j - k - k >= i) { ans += n - j; break; }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}