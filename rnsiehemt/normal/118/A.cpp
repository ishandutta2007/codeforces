#include <cstdio>
#include <cctype>

char v[] = { 'a', 'e', 'i', 'o', 'u', 'y' };

char s[105];

int main()
{
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
        bool f = false; for (int j = 0; j < 6; j++) if (s[i] == v[j]) f = true;
        if (!f) printf(".%c", s[i]);
    }
    printf("\n");
}