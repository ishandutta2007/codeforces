#include <cstdio>
int x1, y1, x2, y2, d;
int main() {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == x2) {
        d = (y1 > y2 ? y1 - y2 : y2 - y1);
        printf("%d %d %d %d\n", x1 + d, y1, x2 + d, y2);
    } else if (y1 == y2) {
        d = (x1 > x2 ? x1 - x2 : x2 - x1);
        printf("%d %d %d %d\n", x1, y1 + d, x2, y2 + d);
    } else if (x1 + y1 != x2 + y2 && x1 - y1 != x2 - y2)
        printf("-1");
    else
        printf("%d %d %d %d\n", x1, y2, x2, y1);
}