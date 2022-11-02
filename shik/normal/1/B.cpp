#include <cstdio>
#include <cstring>
#include <cctype>

int aton(char *s) {
    int x = 0;
    for (int i = 0; s[i]; i++) x = x * 26 + s[i] - 'A' + 1;
    return x;
}

char* ntoa(int x) {
    static char s[10];
    int len = 1, pw = 26;
    while (pw < x) {
        x -= pw;
        pw *= 26;
        len++;
    }
    x--;
    for (int i = 0; i < len; i++) {
        pw /= 26;
        s[i] = 'A' + x / pw;
        x %= pw;
    }
    s[len] = '\0';
    return s;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char buf[80];
        scanf("%s",buf);
        if (buf[0] == 'R' && isdigit(buf[1]) && strchr(buf, 'C')) {
            int r, c;
            sscanf(buf, "R%dC%d", &r, &c);
            printf("%s%d\n", ntoa(c), r);
        } else {
            int r;
            char c[10];
            sscanf(buf, "%[A-Z]%d", c, &r);
            printf("R%dC%d\n", r, aton(c));
        }
    }
    return 0;
}