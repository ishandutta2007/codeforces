#include <cstdio>
#include <algorithm>
#include <cmath>

struct P {
    int d, s;
    bool operator<(const P &p) const {
        return d < p.d;
    }
};

int N, S;
P p[1005];

int main()
{
    scanf("%d%d", &N, &S);
    for (int i = 0; i < N; i++) {
        int x, y; scanf("%d%d%d", &x, &y, &p[i].s);
        p[i].d = x*x+y*y;
    }

    std::sort(p, p+N);

    S = 1000000-S;
    for (int i = 0; i < N; i++) {
        S -= p[i].s;
        if (S <= 0) {
            printf("%lf\n", sqrt(p[i].d));
            return 0;
        }
    }
    printf("-1\n");
}