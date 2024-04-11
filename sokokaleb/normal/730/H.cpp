#include <bits/stdc++.h>

using namespace std;

bitset<111> used;
char s[111][111];
int l[111];
char ans[111];
int x[111];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i]);
        l[i] = strlen(s[i]);
    }
    set<int> k;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x[i]);
        used[x[i]] = 1;
        k.insert(l[x[i]]);
    }
    if (k.size() != 1) {
        printf("No\n");
        return 0;
    }
    int len = *(k.begin());

    for (int i = 0; i < len; ++i) {
        char tmp = s[x[0]][i];
        for (int j = 1; j < m; ++j) {
            if (tmp != s[x[j]][i]) {
                tmp = '?';
            }
        }
        ans[i] = tmp;
    }

    bool can = true;
    for (int i = 1; can && i <= n; ++i) {
        if (!used[i]) {
            bool match = l[i] == len;
            for (int j = 0; match && j < len; ++j) {
                if (s[i][j] == ans[j] || ans[j] == '?') {
                } else match = false;
            }
            can &= !match;
        }
    }

    if (can) printf("Yes\n%s\n", ans);
    else printf("No\n");
    return 0;
}