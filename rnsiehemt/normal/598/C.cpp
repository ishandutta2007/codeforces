#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;

const int MaxN = 100005;

struct P {
    int i;
    ll x, y;
    P() : x(0), y(0) { }
    P(ll xx, ll yy) : x(xx), y(yy) { }
    int quadrant() const {
        if (x >= 0 && y > 0) return 0;
        else if (x > 0 && y <= 0) return 1;
        else if (x <= 0 && y < 0) return 2;
        else return 3;
    }
    ll operator^(P p) const { return x * p.y - y * p.x; }
    ll operator*(P p) const { return x * p.x + y * p.y; }
    ll szsq() { return x*x + y*y; }
    bool operator<(const P &p) const {
        if (quadrant() != p.quadrant()) return quadrant() < p.quadrant();
        else return ((*this) ^ p) < 0;
    }
};

ll sign(ll a) {
    if (a < 0) return -1ll;
    else if (a > 0) return 1ll;
    else return 0ll;
}

int N, besti = -1, bestj = -1;
ll bestn = 0, bestd = 1;
P p[MaxN];

bool less(ll a, ll b, ll c, ll d) {
    assert(b != 0 && d != 0);
    if (b < 0) { a *= -1; b *= -1; }
    if (d < 0) { c *= -1; d *= -1; }
    if (sign(a) != sign(c)) return sign(a) < sign(c);
    bool reverse = false;
    if (a < 0) { reverse = true; a *= -1; c *= -1; }
    if (a/b != c/d) return ((a/b < c/d) ^ reverse);
    else if (!reverse) {
        if (c%d == 0) return false;
        else if (a%b == 0) return true;
        else return less(d, c%d, b, a%b);
    } else {
         if (a%b == 0) return false;
         else if (c%d == 0) return true;
         else return less(b, a%b, d, c%d);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld%lld", &p[i].x, &p[i].y);
        p[i].i = i;
    }
    std::sort(p, p+N);
    for (int i = 0; i < N; i++) {
        int j = (i+1)%N;
        ll n = (p[i]*p[j]) * (p[i]*p[j]) * sign(p[i]*p[j]);
        ll d = p[i].szsq() * p[j].szsq();
        //if (i == 0 || ld(n)/d > ld(bestn)/bestd) {
        //if (i == 0 || ld(n) * bestd > ld(bestn) * d) {
        if (i == 0 || less(bestn, bestd, n, d)) {
            bestn = n;
            bestd = d;
            besti = i;
            bestj = j;
        }
    }
    assert(besti != -1);
    printf("%d %d\n", p[besti].i+1, p[bestj].i+1);
}