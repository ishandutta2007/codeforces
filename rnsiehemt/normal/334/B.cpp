#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int N = 8;

struct P {
    int x, y;
};

bool x(const P &a, const P &b) {
    return a.x < b.x;
}

bool y(const P &a, const P &b) {
    if (a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}

void f(bool a) {
    if (!a) {
        printf("ugly\n");
        exit(0);
    }
}

P p[9];
int x0, x1, x2;

int main()
{
    for (int i = 0; i < N; i++) scanf("%d%d", &p[i].x, &p[i].y);
    std::sort(p, p+N, x);
    f(p[0].x == p[1].x && p[1].x == p[2].x && p[2].x < p[3].x && p[3].x == p[4].x && p[4].x < p[5].x && p[5].x == p[6].x && p[6].x == p[7].x);
    x0 = p[0].x; x1 = p[3].x; x2 = p[5].x;
    std::sort(p, p+N, y);
    f(p[0].y == p[1].y && p[1].y == p[2].y && p[2].y < p[3].y && p[3].y == p[4].y && p[4].y < p[5].y && p[5].y == p[6].y && p[6].y == p[7].y);
    f(p[0].x == x0 && p[1].x == x1 && p[2].x == x2 && p[3].x == x0 && p[4].x == x2 && p[5].x == x0 && p[6].x == x1 && p[7].x == x2);
    printf("respectable\n");
}