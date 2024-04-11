#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pt{
    ll x, y;
    pt() {}
    pt(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    ll operator * (const pt &a) const {
        return x * a.y - y * a.x;
    }
    pt operator - (const pt &a) const {
        return pt(x - a.x, y - a.y);
    }
};

ll turn(pt o, pt a, pt b) {
    return (a - o) * (b - o);
}

const int N = 1e6 + 34;
pt a[N], p;
int l, r, m, n, q;

bool is_in() {
    if (turn(a[0], a[1], p) >= 0) return false;
    if (turn(a[0], p, a[n - 1]) >= 0) return false;
    l = 1;
    r = n - 1;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (turn(a[0], a[m], p) <= 0)
            l = m;
        else
            r = m;
    }
    if (turn(a[l], a[l + 1], p) < 0)
        return true;
    return false;
}

int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d%I64d", &a[i].x , &a[i].y);
    scanf("%d", &q);

    while (q--) {
        scanf("%I64d%I64d", &p.x, &p.y);
        //cerr << p.x << " " << p.y << "\n";
        if (!is_in()) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}