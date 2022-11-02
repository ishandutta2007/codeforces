#include <iostream>

int main()
{
    long long ans = 1ll;
    long long a; std::cin >> a;
    for (long long d = 1ll; d <= a; d *= 3ll) {
        if (a % d == 0ll) continue;
        else ans = std::max(ans, (a/d) + 1ll);
    }
    std::cout << ans << std::endl;
}