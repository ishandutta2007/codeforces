#include <cstdio>
#define abs(x, y) (x > y ? x - y : y - x)
int a, b, c[3];
int main() {
    scanf("%d%d", &a, &b);
    for (int i = 1; i < 7; i++) {
        if (abs(i, a) == abs(i, b)) c[1]++;
        if (abs(i, a) < abs(i, b)) c[0]++;
        if (abs(i, a) > abs(i, b)) c[2]++;
    }
    printf("%d %d %d\n", c[0], c[1], c[2]);
}