#include <cstdio>
#include <cstring>
int t, len, ans[7];
char s[20];
int main() {
    scanf("%d", &t);
    while (t--) {
        len = 0;
        scanf("%s", s);
        for (int i = 0; i < 12; i++)
            if (s[i] == 'X') {ans[len++] = 1; break;}
        for (int i = 0; i < 6; i++)
            if (s[i] == 'X' && s[i + 6] == 'X') {ans[len++] = 2; break;}
        for (int i = 0; i < 4; i++)
            if (s[i] == 'X' && s[i + 4] == 'X' && s[i + 8] == 'X') {
                ans[len++] = 3;
                break;
            }
        for (int i = 0; i < 3; i++)
        if (s[i] == 'X' && s[i + 3] == 'X' && s[i + 6] == 'X' && s[i + 9] == 'X') {
            ans[len++] = 4;
            break;
        }
        for (int i = 0; i < 2; i++)
        if (s[i] == 'X' && s[i + 2] == 'X' && s[i + 4] == 'X' && s[i + 6] == 'X' && s[i + 8] == 'X' && s[i + 10] == 'X') {
            ans[len++] = 6;
            break;
        }
        ans[len++] = 12;
        for (int i = 0; i < 12; i++)
        if (s[i] != 'X') {
            len--;
            break;
        }
        printf("%d", len);
        for (int i = 0; i < len; i++) printf(" %dx%d", ans[i], 12 / ans[i]);
        printf("\n");
    }
}