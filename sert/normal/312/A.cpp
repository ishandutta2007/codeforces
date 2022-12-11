#include <cstdio>
#include <cstring>
char s[1234];
int n, m, a1, a2;
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d", &n);
    gets(s);
    while (n--) {
        gets(s);
        m = strlen(s);
        if (m < 5) printf("OMG>.< I don't know!\n");
        else {
            if (s[0] == 'm' && s[1] == 'i' && s[2] == 'a' && s[3] == 'o' && s[4] == '.') a1 = 1; else a1 = 0;
            if (s[m - 1] == '.' && s[m - 2] == 'a' && s[m - 3] == 'l' && s[m - 4] == 'a' && s[m - 5] == 'l') a2 = 1; else a2 = 0;
            if (a1 == 1 && a2 == 0) printf("Rainbow's\n");
            if (a1 == 0 && a2 == 1) printf("Freda's\n");
            if (a1 + a2 != 1) printf("OMG>.< I don't know!\n");
        }
    }
}