#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n, m, ans;
char s[N];
char t[N];
int cnt[N];

int main() {
    strcpy(t, "auBlbsr");
    gets(s);
    n = strlen(s), m = strlen(t);
    for (int j = 0; j < m; j ++) {
        for (int i = 0; i < n; i ++) {
            if (s[i] == t[j]) cnt[j] ++;
        }
    }
    ans = min(cnt[0], cnt[1]) / 2;
    for (int i = 2; i < m; i ++) ans = min(ans, cnt[i]);
    printf("%d\n", ans);
}