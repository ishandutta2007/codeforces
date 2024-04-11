#include <cstdio>
#include <cstring>

int N;
char s[1000005];
long long h, a;

bool f(int i) {
    for (int j = 0; j < 5; j++) if (s[i+j] != "heavy"[j]) return false;
    /* else */ return true;
}

bool g(int i) {
    for (int j = 0; j < 5; j++) if (s[i+j] != "metal"[j]) return false;
    /* else */ return true;
}

int main()
{
    scanf("%s", s); N = strlen(s);
    for (int i = 0; i+5 <= N; i++) {
        if (f(i)) h++;
        if (g(i)) a += h;
    }
    printf("%I64d\n", a);
}