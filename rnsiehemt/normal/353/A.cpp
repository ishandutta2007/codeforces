#include <cstdio>

int N;
int x, y;
int X, Y;
bool f;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &x, &y);
        X += x; Y += y;
        if ((x % 2) != (y % 2)) f = true;
    }
    if ((X % 2) != (Y % 2)) printf("-1\n");
    else if ((X % 2) == 0) printf("0\n");
    else if (f) printf("1\n");
    else printf("-1\n");
}