#include <iostream>

long long n, len, lst, now, sum;

int main() {
    std::cin >> n; n--;
    for (len = lst = 1; ; len++, lst = now) {
        now = lst * 10;
        if (n < sum + (now - lst) * len) {
            n -= sum;
            std::cout << std::to_string(lst + n / len)[n % len];
            break;
        }
        sum += (now - lst) * len;
    }
    return 0;
}