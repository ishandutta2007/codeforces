#include <cstdio>
#include <algorithm>

int N, M;
int min[32], max[32];
bool seen[32][250];
bool found;
int a[32];

void f(int i, int s) {
    if (seen[i][s]) return;
    else if (i == N) {
        if (s == M) found = true;
        return;
    }
    else seen[i][s] = true;

    for (int j = min[i]; j <= max[i]; j++) {
        f(i+1, s+j);
        if (found) {
            a[i] = j;
            return;
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d%d", &min[i], &max[i]);
    f(0, 0);
    if (found) {
        printf("YES\n");
        for (int i = 0; i < N; i++) { printf("%d ", a[i]); } printf("\n");
    }
    else printf("NO\n");
}