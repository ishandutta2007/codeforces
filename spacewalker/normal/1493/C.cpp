#include <bits/stdc++.h>

using namespace std;

void solve() {
    static char s[101000];
    int n, k; scanf("%d %d", &n, &k);
    scanf("%s", s);
    if (n % k != 0) {
        printf("-1\n");
        return;
    }
    vector<int> acount(26);
    for (int i = 0; s[i]; ++i) ++acount[s[i] - 'a'];
    for (int i = n - 1; i >= 0; --i) {
        for (char c = s[i] + (i == n - 1 ? 0 : 1); c <= 'z'; ++c) {
            vector<int> whatif = acount;
            --whatif[s[i] - 'a']; ++whatif[c - 'a'];
            int needComplete = 0;
            for (int v : whatif) needComplete += (v % k ? k - (v % k) : 0);
            if (needComplete <= n - 1 - i) {
                vector<int> needed(26);
                for (int x = 0; x < 26; ++x) needed[x] = (whatif[x] % k ? k - (whatif[x] % k) : 0);
                needed[0] += (n - 1 - i) - needComplete;
//                for (int x = 0; x < 26; ++x) for (int y = 0; y < needed[x]; ++y) printf("%c", x + 'a');
//                printf("\n");
                s[i] = c;
                for (int j = i + 1, cchar = 0; j < n; ++j) {
                    while (cchar < 26 && needed[cchar] == 0) ++cchar;
                    if (cchar < 26) --needed[cchar];
                    s[j] = (cchar + 'a');
                }
                printf("%s\n", s);
                return;
            }
        }
        --acount[s[i] - 'a'];
    }
    printf("-1\n");
    return;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}