#include <cstdio>
#include <iostream>

std::string opt;

inline char query(int l, int r) {
    char c;
    std::cout << "? " << l << " " << r << std::endl;
    std::cin >> c;
    return c;
}
inline void answer(int x) {
    std::cout << "! " << x << std::endl;
}

int main() {
    while (std::cin >> opt) {
        if (opt == "end") { break; }
        for (int ll = 0, rr = 1; ; ll = rr, rr <<= 1) {
            if (query(ll, rr) == 'x') {
                int ans = rr;
                for (int l = ll + 1, r = rr, mid; l <= r; ) {
                    mid = l + r >> 1;
                    if (query(ll, mid) == 'x') { ans = mid; r = mid - 1; } else { l = mid + 1; }
                }
                answer(ans);
                break;
            }
        }
    }
    return 0;
}