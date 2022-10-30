#include <cstdio>
#include <cctype>
#include <cstdlib>

char s[105], t[105];

void ans(int i) {
    printf("%d\n", i);
    exit(0);
}

int main()
{
    scanf(" %s %s", s, t);
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]); t[i] = tolower(t[i]);
        if (s[i] < t[i]) ans(-1);
        else if (t[i] < s[i]) ans(1);
    }
    ans(0);
}