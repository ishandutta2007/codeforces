#include <bits/stdc++.h>
using namespace std;

#define N 1001

bool cnt[N];
char s[N];

int main() {
    int T, n;
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s);
        n = strlen(s);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && s[j] == s[i]) j ++;
            if (j - i & 1) cnt[s[i]-'a'] = 1;
        }
        for (int i = 0; i < 26; i ++) if (cnt[i]) putchar(i + 'a'); puts("");
    }

    return 0;
}