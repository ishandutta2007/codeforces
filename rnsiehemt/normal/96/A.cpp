#include <cstdio>

char s[105];

int main()
{
    scanf("%s", s);
    for (int i = 6; s[i]; i++) {
        bool f = true;
        for (int j = i-6; j < i; j++)
            if (s[j] != s[i]) f = false;
        if (f) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}