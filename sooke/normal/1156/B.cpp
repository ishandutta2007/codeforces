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

int n, nt, cnt[100];
std::string str, ans, a, b;
std::vector<int> vec;

bool check() {
    for (int i = 1; i < n; i++) {
        if (ans[i - 1] + 1 == ans[i] || ans[i - 1] - 1 == ans[i]) { return false; }
    }
    return true;
}

int main() {
    for (std::cin >> nt; nt; nt--) {
        std::cin >> str; n = str.size(); a = b = "";
        for (int i = 0; i < n; i++) { cnt[str[i] - 'a']++; }
        for (int i = 0, j = 0, f = 0, x = -666; i < 50; i++) {
            if (cnt[i] > 0 && cnt[i + 1] > 0) {
                for (; cnt[i]; cnt[i]--) { b += (char) ('a' + i); }
                for (; cnt[i + 1]; cnt[i + 1]--) { a = f ? (char) ('a' + i + 1) + a : a + (char) ('a' + i + 1); }
                i++; x = i;
            } else if (cnt[i] > 0) {
                if (x + 1 == i) {
                    for (; cnt[i]; cnt[i]--) { b += (char) ('a' + i); }
                } else {
                    for (; cnt[i]; cnt[i]--) { a += (char) ('a' + i); } f = 1;
                }
            }
        }
        ans = a + b;
        if (check()) { std::cout << ans << std::endl; }
        else { std::cout << "No answer\n"; }
    }
    return 0;
}