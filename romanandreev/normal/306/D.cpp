#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
int n;
struct pnt {
    ld x, y;
    pnt() {
    }
    pnt(ld x, ld y):x(x),y(y){
    }
};
pnt operator + (pnt a, pnt b) {
    return pnt(a.x + b.x, a.y + b.y);
}
pnt operator - (pnt a, pnt b) {
    return pnt(a.x - b.x, a.y - b.y);
}
pnt operator * (ld c, pnt a) {
    return pnt(c * a.x, c * a.y);
}
ld sp(pnt a, pnt b) {
    return a.x * b.x + a.y * b.y;
}
ld vp(pnt a, pnt b) {
    return a.x * b.y - a.y * b.x;
}

pnt p[1000];
ld l[1000];
ld a[1000];
struct line {
    ld a, b, c;
    line() {
    }
    line(pnt p, ld alp) {
        pnt v = pnt(cos(alp), sin(alp));
        a = -v.y;
        b = v.x;
        c = -(a * p.x + b * p.y);
    }
};
pnt inters(line a, line b) {
    ld dd = a.a * b.b - a.b * b.a;
    ld dx = a.c * b.b - a.b * b.c;
    ld dy = a.a * b.c - a.c * b.a;
    return pnt(-dx/dd, -dy/dd);
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%d", &n);
    if (n <= 4) {
        printf("No solution\n");
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        l[i] = 800 - i * 0.005; 
    }
    p[0] = pnt(0, 0);
    ld alp = 2 * M_PI / n;
    for (int i = 0; i < n - 1; i++) {
        p[i + 1] = p[i] + l[i] * pnt(cos(alp * i), sin(alp * i));
    }    
    p[n - 1] = inters(line(p[0], -alp), line(p[n - 2], -2 * alp));
    p[n] = p[0];
    for (int i = 0; i < n; i++) {
        l[i] = sqrt(sp(p[i + 1] - p[i], p[i + 1] - p[i]));
        assert(l[i] <= 1000);
    }        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            assert(fabs(l[j] - l[i]) > 1e-3);
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = -atan2(vp(p[i + 1] - p[i], p[i] - p[(i + n - 1) % n]), 
                      sp(p[i + 1] - p[i], p[i] - p[(i + n - 1) % n]));
        assert(fabs(a[i] - alp) < 1e-3);
    }
    for (int i = 0; i < n; i++) {
        printf("%.18lf %.18lf\n", (double)p[i].x, (double)p[i].y);
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}