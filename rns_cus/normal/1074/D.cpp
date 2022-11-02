#include <bits/stdc++.h>
using namespace std;

#define N 200200

typedef pair <int, int> pii;

map <int, pii> nxt;

pii find_nxt(int u) {
    if (nxt.find(u) == nxt.end()) nxt[u] = pii(u, 0);
    pii p = nxt[u];
    if (p.first == u) return p;
    pii t = find_nxt(p.first);
    return nxt[u] = pii(t.first, t.second ^ p.second);
}

int main() {
    int q, last = 0;
    scanf("%d", &q);
    while (q --) {
        int x, l, r;
        scanf("%d %d %d", &x, &l, &r);
        l ^= last, r ^= last;
        if (l > r) swap(l, r);
        if (x == 1) {
            scanf("%d", &x); x ^= last;
            pii p1 = find_nxt(l), p2 = find_nxt(r + 1);
            if (p1.first == p2.first) continue;
            x ^= p1.second ^ p2.second;
            if (p1.first < p2.first) nxt[p1.first] = pii(p2.first, x);
            else nxt[p2.first] = pii(p1.first, x);
        }
        else {
            pii p1 = find_nxt(l), p2 = find_nxt(r + 1);
            if (p1.first == p2.first) printf("%d\n", last = p1.second ^ p2.second);
            else puts("-1"), last = 1;
        }
    }
}