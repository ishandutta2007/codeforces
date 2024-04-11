#include <cstdio>
#include <cctype>

char s[105];

int main()
{
    scanf("%s", s);
    bool f = true;
    for (int i = 1; s[i]; i++)
        if (islower(s[i])) f = false;
    if (f) {
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) s[i] = toupper(s[i]);
            else /* isupper(s[i]) */ s[i] = tolower(s[i]);
        }
    }
    printf("%s\n", s);
}