#include <cstdio>
#include <cstring>

int N;
char s[15];
bool y[15];

int main()
{
    scanf(" %s", s);
    N = strlen(s);
    for (int i = N; i < 15; i++) s[i] = '\0';
    y[0] = true;
    for (int i = 0; i < N; i++) {
        if (y[i]) {
            if (s[i] == '1') {
                y[i+1] = true;
                if (s[i+1] == '4') {
                    y[i+2] = true;
                    if (s[i+2] == '4') {
                        y[i+3] = true;
                    }
                }
            }
        }
    }
    printf("%s\n", y[N] ? "YES" : "NO");
}