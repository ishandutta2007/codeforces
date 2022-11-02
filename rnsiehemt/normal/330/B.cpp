#include <cstdio>

int N, M;
bool z[1010];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        z[a] = z[b] = true;
    }

    for (int i = 0; i < N; i++) {
        if (z[i] == false) {
            printf("%d\n", N-1);
            for (int j = 0; j < N; j++)
                if (j != i) printf("%d %d\n", i+1, j+1);
            break;
        }
    }
}