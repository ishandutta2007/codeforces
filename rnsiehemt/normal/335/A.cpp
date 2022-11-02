#include <cstdio>
#include <cstring>

int M, N;
char s[1005];
int c[28];

int main()
{
    scanf(" %s%d", s, &N); M = strlen(s);
    for (int i = 0; i < M; i++) c[s[i]-'a']++;
    
    for (int i = 1; i <= 1000; i++) {
        char t[1005]; int T = 0;
        for (int j = 0; j < 26; j++) {
            int k = (c[j] / i + bool(c[j] % i));
            while (T <= N && k) {
                t[T++] = 'a'+j;
                k--;
            }
        }
        if (T <= N) {
            while (T < N) t[T++] = 'a';
            t[T] = '\0';
            printf("%d\n%s\n", i, t);
            return 0;
        }
    }
    printf("-1\n");
}