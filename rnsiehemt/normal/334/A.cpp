#include <cstdio>

int main()
{
    int N; scanf("%d", &N);
    int a = 1, b = N*N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j+j < N; j++) printf("%d %d ", a++, b--);
        printf("\n");
    }
}