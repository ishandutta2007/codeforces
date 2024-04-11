#include <cstdio>
#include <cstring>
#include <cctype>

int N, M;
char s[105];
int ans;
char a[100];
int A;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        A = 99;
        ans = 0;
        scanf(" %s", s); M = strlen(s);

        int c = 0;
        for (int j = 1; j < M; j++)
            if ((bool)isalpha(s[j]) != (bool)isalpha(s[j-1])) c++;
        
        if (c == 1) {
            int p = 26, K = 1;
            while (isalpha(s[K])) {
                ans += p;
                p *= 26;
                K++;
            }
            p = 1;
            for (int j = K-1; j >= 0; j--) {
                ans += (s[j]-'A')*p;
                p *= 26;
            }
            printf("R%sC%d\n", s+K, ans+1);
        }
        else {
            int K = 1;
            while (s[K] != 'C') K++;
            s[K] = '\0';
            K++;
            int v; sscanf(s+K, "%d", &v); v--;
            int L = 1, p = 26;
            while (p <= v) {
                v -= p;
                p *= 26;
                L++;
            }
            a[A] = '\0';
            for (int i = 0; i < L; i++) {
                a[--A] = 'A'+(v%26);
                v /= 26;
            }
            printf("%s%s\n", a+A, s+1);
        }
    }
}