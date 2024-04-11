#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef int ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;
const ld eps = 1e-10;
const ll C = 7;

struct pt {
    ll x, y;
    pt() {}
    pt(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    long double dist(const pt &a) {
        return sqrtl((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
    }
};

int n, m;

pt get1() {
    if (rand() % 2)
        return pt(0, rand() % min(C, n + 1));
    else
        return pt(rand() % min(C, m + 1), 0);
}

pt get2() {
    if (rand() % 2)
        return pt(m, n - rand() % min(C, n + 1));
    else
        return pt(m - rand() % min(C, m + 1), n);
}

pt g1() {
    return pt(rand() % min(4, (m + 1)), rand() % min(4, (n + 1)));
}

pt g2() {
    return pt(m - rand() % min(4, (m + 1)), n - rand() % min(4, (n + 1)));
}

bool eq(pt aa, pt bb) {
    return (aa.x == bb.x && aa.y == bb.y);
}

ll x1, y1, x2, y2;
long double ans = -1, cur;
//int n, m;
pt a1, a2, a3, a4;
pt b1, b2, b3, b4;

int main()
{
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> m >> n;
    for (int i = 0; i < 1000002; i++) {
        a1 = get1();
        a2 = get2();
        a3 = get1();
        a4 = get2();
        if (i < 2) swap(n, m);
        if (i == 0) {
            a1 = pt(0, 0);
            a2 = pt(n, m);
            a3 = pt(0, m);
            a4 = pt(n, 0);
        }
        if (i == 1) {
            a1 = pt(0, 0);
            a2 = pt(n, m);
            a3 = pt(n, 0);
            a4 = pt(0, m);
        }
        if (i < 2) swap(n, m);
        if (eq(a1, a2) || eq(a1, a3) || eq(a1, a4) || eq(a2, a3) || eq(a2, a4) || eq(a3, a4))
            continue;
        cur = a1.dist(a2) + a2.dist(a3) + a3.dist(a4);
        if (cur > ans + eps) {
            ans = cur;
            b1 = a1;
            b2 = a2;
            b3 = a3;
            b4 = a4;
        }
    }
    for (int i = 0; i < 6000002; i++) {
        a1 = g1();
        a2 = g2();
        a3 = g1();
        a4 = g2();
        if (eq(a1, a2) || eq(a1, a3) || eq(a1, a4) || eq(a2, a3) || eq(a2, a4) || eq(a3, a4))
            continue;
        cur = a1.dist(a2) + a2.dist(a3) + a3.dist(a4);
        if (cur > ans + eps) {
            ans = cur;
            b1 = a1;
            b2 = a2;
            b3 = a3;
            b4 = a4;
        }
    }
    printf("%d %d\n", b1.x, b1.y);
    printf("%d %d\n", b2.x, b2.y);
    printf("%d %d\n", b3.x, b3.y);
    printf("%d %d\n", b4.x, b4.y);

    return 0;
}