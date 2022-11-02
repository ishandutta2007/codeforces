#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

typedef double real;

const real eps = 1e-9;

struct P {
    real x, y;
    P() : x(0.0), y(0.0) { }
    P(real xx, real yy) : x(xx), y(yy) { }
    bool operator<(const P &p) const {
        if (y == p.y) return x < p.x;
        else return y < p.y;
    }
};

P operator-(P a, P b) {
    return P(a.x-b.x, a.y-b.y);
}

real operator^(P a, P b) {
    return a.x*b.y - a.y*b.x;
}

bool right(P a, P b, P c) {
    return ((b-a)^(c-b)) < -eps;
}

real distsq(P a) {
    return a.x*a.x + a.y*a.y;
}

int N;
std::vector<P> p /* points */;
std::vector<real> d /* distances squared between points */;
bool valid[3005];
int H;
P h[3005];

void get_hull() {
    H = 0;

    for (int i = 0; i < N; i++) {
        if (!valid[i]) continue;
        while (H >= 2 && !right(h[H-2], h[H-1], p[i])) H--;
        h[H++] = p[i];
    }
    int midh = H;
    for (int i = N-2; i >= 0; i--) {
        if (!valid[i]) continue;
        while (H > 1 && H > midh && !right(h[H-2], h[H-1], p[i])) H--;
        h[H++] = p[i];
    }
    
    if (H) H--;
}

bool trycentre(P o /* origin or centre */, real r /* radius squared */) {
    for (int i = 0; i < N; i++) valid[i] = (distsq(o-p[i]) > r-eps);

    get_hull();

    if (H < 2) return false;
    else if (H == 2) return (distsq(h[0]-h[1]) > r-eps);
    else /* H > 2 */ {
        int j = 0;
        for (int i = 0; i < H; i++) {
            while (((h[(i+1)%H] - h[i]) ^ (h[(j+1)%H] - h[j])) < -eps) j = (j+1 == H ? 0 : j+1);
            if (distsq(h[i] - h[j]) > r-eps) return true;
            else if (distsq(h[(i+1)%H] - h[j]) > r-eps) return true;
        }
        /* else */ return false;
    }
}

int start_trying_here = 0;
bool tryradius(real r /* radius squared */) {
    for (int i = start_trying_here; i < N; i++) {
        if (trycentre(p[i], r)) {
            //start_trying_here = i;
            return true;
        }
    }
    /* else */ return false;
}

int main()
{
    scanf("%d", &N);
    p.resize(N); for (int i = 0; i < N; i++) scanf("%lf%lf", &p[i].x, &p[i].y);

    std::sort(p.begin(), p.end());

    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            d.push_back(distsq(p[i]-p[j]));

    std::sort(d.begin(), d.end());

    int lo = 0, hi = (int)d.size();
    while (hi-lo > 1) {
        int mid = (lo+hi)/2;
        if (tryradius(d[mid])) lo = mid;
        else hi = mid;
    }

    printf("%.7lf\n", sqrt(d[lo])/2.0);
}