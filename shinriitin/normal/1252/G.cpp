#include <bits/stdc++.h>

const int max_N = 300010;

int n;
char s[max_N];
std::vector<std::pair<char, int>> vec;

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && s[i] == s[j]; ++j);
        vec.emplace_back(s[i], j - i);
    }
    int ans = 0;
    if (vec.size() % 2 == 0) {
        puts("0");
        return 0;
    }
    int l, r;
    for (l = 0, r = vec.size() - 1; l < r; ++l, --r) {
        if (vec[l].first != vec[r].first) {
            puts("0");
            return 0;
        }
        if (vec[l].second + vec[r].second < 3) {
            puts("0");
            return 0;
        }
    }
    if (vec[l].second < 2) {
        puts("0");
        return 0;
    }
    printf("%d\n", vec[l].second + 1);
    return 0;
}