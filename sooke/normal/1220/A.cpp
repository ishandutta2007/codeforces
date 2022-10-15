#include <bits/stdc++.h>

int n, m, cnt[1000];
std::string str;

int main() {
    std::cin >> n >> str;
    for (int i = 0; i < n; i++) { cnt[str[i]]++; }
    m = std::min(cnt['o'], cnt['e']);
    for (int i = 0; i < m; i++) {
        if (cnt['n']) {
            printf("1 "); cnt['n']--;
        } else if (cnt['z'] && cnt['r']) {
            printf("0 "); cnt['z']--; cnt['r']--;
        }
    }
    return 0;
}