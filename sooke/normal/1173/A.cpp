#include <cstdio>

int x, y, z;

int main() {
    scanf("%d%d%d", &x, &y, &z);
    if (x > y + z) { printf("+\n"); }
    else if (y > x + z) { printf("-\n"); }
    else { printf("%s\n", z ? "?" : "0"); }
    return 0;
}