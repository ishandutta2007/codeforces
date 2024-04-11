#include <cstdio>

int main() {
    int N, x, y;
    scanf("%d", &N);
    for (; N>0; x++)
        for (y = 0; y < 3; y++)
            if (x + y & 1 && N--)
                printf("%d %d\n", x, y);
}