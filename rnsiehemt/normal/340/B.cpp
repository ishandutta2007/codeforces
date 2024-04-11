#include <cstdio>
#include <algorithm>

struct P {
    int x, y;
    P() : x(0), y(0) { }
    P(int xx, int yy) : x(xx), y(yy) { }
};

P operator-(P a, P b) {
    return P(a.x-b.x, a.y-b.y);
}

int operator^(P a, P b) {
    return a.x*b.y - a.y*b.x;
}

bool left(P a, P b, P c) {
    return ((b-a)^(c-b)) > 0;
}

// isn't actually area but since it is only used for
// comparison purposes we don't need to worry about
// dividing by 2 and stuff
int area(P a, P b, P c) {
    return ((b-a)^(c-b));
}

int N;
P p[305];
double ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d%d", &p[i].x, &p[i].y);

    for (int a = 0; a < N; a++) {
        for (int b = a+1; b < N; b++) {
            int l = -1, larea = -1;
            int r = -1, rarea = -1;
            for (int c = 0; c < N; c++) {
                if (a == c || b == c) continue;
                if (left(p[a], p[b], p[c])) {
                    int carea = std::abs(area(p[a], p[b], p[c]));
                    if (carea > larea) {
                        l = c;
                        larea = carea;
                    }
                }
                else /* right(...) */ {
                    int carea = std::abs(area(p[a], p[b], p[c]));
                    if (carea > rarea) {
                        r = c;
                        rarea = carea;
                    }
                }
            }
            if (l != -1 && r != -1) {
                ans = std::max(ans, (larea+rarea)/2.0);
            }
        }
    }

    printf("%lf\n", ans);
}