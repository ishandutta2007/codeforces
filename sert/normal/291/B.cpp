#include <cstdio>
#include <cstring>
char s[123456];
int n;
bool in, pr;
int main() {
    gets(s); n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '"') {
            in = !in;
            if (in) printf("<");
            else printf(">\n");
            continue;
        }
        if (in) {
            printf("%c", s[i]);
            continue;
        }
        if (s[i] != ' ') {
            if (!pr) printf("<");
            pr = true;
            printf("%c", s[i]);
            continue;
        }
        if (s[i] == ' ' && pr) {
            pr = false;
            printf(">\n");
        }
    }
    if (pr) printf(">\n");
}