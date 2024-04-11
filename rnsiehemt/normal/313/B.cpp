#include <cstdio>
#include <cstring>

int N, M;
char s[100005];
int q[100005];

int main()
{
    scanf(" %s", s); N = strlen(s);
    for (int i = 0; i < N; i++) q[i+1] = q[i] + (s[i] == s[i+1]);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", q[r-1]-q[l-1]);
    }
}