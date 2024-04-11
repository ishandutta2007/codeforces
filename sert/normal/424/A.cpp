#include <cstdio>
char s[345];
int n, a1, a2, ans;
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d\n%s", &n, s);
    for (int i = 0; i < n; i++) if (s[i] == 'x') a1++; else a2++;
    ans = (a1 < a2 ? a2 - a1 : a1 - a2);
    for (int i = 0; i < n; i++) {
        if (a1 > a2 && s[i] == 'x') {
            a2 += 2;
            s[i] = 'X';
        }
        if (a1 < a2 && s[i] == 'X') {
            a1 += 2;
            s[i] = 'x';
        }
    }
    printf("%d\n%s\n", ans / 2, s);
}