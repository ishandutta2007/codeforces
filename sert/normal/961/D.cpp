#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)3e5 + 34;

struct pt {
    ll x, y;
    pt(ll xx = 0, ll yy = 0) {
        x = xx;
        y = yy;
    }
    pt operator - (const pt &a) const {
        return pt(x - a.x, y - a.y);
    }
    ll operator * (const pt &a) const {
        return x * a.y - y * a.x;
    }
};

bool isOnLine(const pt &a, const pt &b, const pt &c) {
    return ((a - b) * (c - b) == 0);
}

void solve() {
    auto t0 = clock();
    int n, xx, yy;
    scanf("%d", &n);
    vector<pt> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &xx, &yy);
        a[i] = pt(xx, yy);
    }
    if (n == 1) {
        a.push_back(a[0]);
        n = 2;
    }
    while (clock() - t0 < CLOCKS_PER_SEC * 1.5) {
        int v1 = rand() % n;
        int v2 = rand() % n;
        if (v1 == v2) continue;
        vector<pt> v;
        for (int i = 0; i < n; i++) {
            if (!isOnLine(a[v1], a[v2], a[i])) v.push_back(a[i]);
        }
        bool fail = false;
        for (int i = 2; i < (int)v.size(); i++) {
            if (!isOnLine(v[0], v[1], v[i])) fail = true;
        }
        if (!fail) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    init();
	solve();
	//solve();
	//solve();
    return 0;
}