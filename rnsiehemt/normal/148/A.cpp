#include <cstdio>

int a, b, c, d, e;
int A;

int main()
{
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    for (int i = 1; i <= e; i++)
        if ((i%a)*(i%b)*(i%c)*(i%d) == 0) A++;
    printf("%d\n", A);
}