#include <cstdio>

char s[105];

int main()
{
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}