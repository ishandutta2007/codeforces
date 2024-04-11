#include <cstdio>
int a, b, c, x, y, z;
int main() {
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 0; i < 2100000; i++) {
        y = b - i;
        z = c - y;
        if (a == i + z && y >= 0 && z >= 0) {
            printf("%d %d %d\n", i, y, z);
            return 0;
        }
    }
    printf("Impossible\n");
}