#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, cnt[2];
char s[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n; scanf("%d", &n);
        memset(cnt, 0, sizeof cnt);
        bool fg = 1;
        for (int i = 0; i < n; i ++) {
            scanf("%s", s);
            if (strlen(s) & 1) fg = 0;
            for (int j = 0; s[j]; j ++) cnt[s[j]-'0'] ++;
        }
        if (fg && cnt[0] & 1 && cnt[1] & 1) n --;
        printf("%d\n", n);
    }

    return 0;
}