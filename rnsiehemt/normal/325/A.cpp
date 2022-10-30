#include <cstdio>
#include <algorithm>

const int inf = 31400;

int N;
int X1 = inf, Y1 = inf, X2, Y2;
int x1, y1, x2, y2;
int area;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        X1 = std::min(X1, x1); Y1 = std::min(Y1, y1);
        X2 = std::max(X2, x2); Y2 = std::max(Y2, y2);
        area += (y2-y1)*(x2-x1);
    }
    if (Y2-Y1 == X2-X1 && (Y2-Y1)*(X2-X1) == area) printf("YES\n");
    else printf("NO\n");
}