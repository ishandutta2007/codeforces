#include <bits/stdc++.h>
using namespace std;

#define N 500500

int n, m, c;

struct frd {
    int t, a, b;
    void in() {
        scanf("%d %d %d", &t, &a, &b);
    }
    bool operator < (const frd &f) const {
        return t < f.t;
    }
} f[N];

typedef pair <int, int> pii;

multiset <pii> s;

void solve() {
    scanf("%d %d %d", &n, &m, &c);
    s.clear();
    int tot; scanf("%d", &tot);
    s.insert(pii(0, tot));
    for (int i = 0; i < n; i ++) f[i].in();
    sort(f, f + n); f[n].t = m;
    long long ans = 0;
    for (int i = 0, lst = 0; i <= n; i ++) {
        int t = f[i].t - lst; pii p;
        if (tot < t) {puts("-1"); return;}
        tot -= t;
        while (t > 0) {
            p = *s.begin(); s.erase(s.begin());
            t -= p.second; ans += 1ll * p.first * p.second;
        }
        if (t < 0) s.insert(pii(p.first, -t)), ans += 1ll * t * p.first;
        p = pii(f[i].b, f[i].a);
        s.insert(p), tot += p.second;
        if (tot > c) {
            while (tot > c) p = (*--s.end()), s.erase(--s.end()), tot -= p.second;
            if (tot < c) s.insert(pii(p.first, c - tot)), tot = c;
        }
        lst = f[i].t;
    }
    printf("%lld\n", ans);
}

int main() {
    int q;
    scanf("%d", &q);
    while (q --) solve();
}