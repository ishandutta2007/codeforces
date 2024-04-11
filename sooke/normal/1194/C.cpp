#include <bits/stdc++.h>

int T, cnt[100];
std::string s, t, p;

bool check() {
    for (int i = 0, j = 0, _j; i < (int) s.size(); i++) {
        for (_j = j; j < (int) t.size() && s[i] != t[j]; j++);
        if (j == (int) t.size()) {
            return false;
        } else {
            for (int k = _j; k < j; k++) { cnt[t[k] - 'a']--; }
            j++;
        }
    }
    for (int i = 0; i < 30; i++) {
        if (cnt[i] < 0) { return false; }
    }
    return true;
}

int main() {
    for (scanf("%d", &T); T; T--) {
        std::cin >> s >> t >> p; s += "|"; t += "|";
        for (int i = 0; i < 30; i++) { cnt[i] = 0; }
        for (int i = 0; i < (int) p.size(); i++) { cnt[p[i] - 'a']++; }
        printf("%s\n", check() ? "YES" : "NO");
    }
    return 0;
}