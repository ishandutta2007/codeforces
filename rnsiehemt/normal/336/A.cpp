#include <cstdio>

int x, y;

int main()
{
    scanf("%d%d", &x, &y);
    if (x < 0) {
        if (y > 0) printf("%d %d %d %d\n", x-y, 0, 0, y-x);
        else printf("%d %d %d %d\n", x+y, 0, 0, x+y);
    }
    else {
        if (y > 0) printf("%d %d %d %d\n", 0, x+y, x+y, 0);
        else printf("%d %d %d %d\n", 0, y-x, x-y, 0);
    }
}