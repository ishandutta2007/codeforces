#include <cstdio>
#include <cstring>
char s[34], k[34];
int pos, sl, kl, kol;
int main() {
    scanf("%s", s);
    sl = strlen(s);
    for (int i = 0; i < sl; i++)
        if (s[i] == '|') pos = i;
    scanf("%s", k);
    kl = strlen(k);
    kol = (sl + kl - 1) / 2;
    if ((sl + kl) % 2 == 0 || kl + pos < kol || pos > kol) {
        printf("Impossible\n");
        return 0;
    }
    for (int i = 0; i < pos; i++)
        printf("%c", s[i]);
    for (int i = 0; i < kol - pos; i++)
        printf("%c", k[i]);
    printf("|");
    for (int i = kol - pos; i < kl; i++)
        printf("%c", k[i]);
    for (int i = pos + 1; i < sl; i++)
        printf("%c", s[i]);
}