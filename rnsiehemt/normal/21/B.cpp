#include <cstdio>

int main()
{
    int a, b, c, x, y, z;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
    if ((a == 0 && b == 0 && c != 0) || (x == 0 && y == 0 && z != 0)) printf("0\n");
    else if (a*y == b*x && b*z == c*y && c*x == a*z) printf("-1\n");
    else if (a*y == b*x) printf("0\n");
    else printf("1");
}