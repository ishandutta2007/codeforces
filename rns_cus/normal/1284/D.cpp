#include <bits/stdc++.h>
using namespace std;

#define N 200100

struct lec{
    int sa, ea, sb, eb;
    bool operator < (const lec &l) const {
        return ea > l.ea;
    }
    void in() {scanf("%d %d %d %d", &sa, &ea, &sb, &eb);}
} l[N];

bool cmp(const lec &a, const lec &b) {
    return a.sa < b.sa;
}

int n, m, x[N], f[N];

void update(int x, int val) {
    for (; x <= m; x += x & -x) f[x] = max(f[x], val);
}

int query(int x) {
    int rlt = 0;
    for (; x; x -= x & -x) rlt = max(rlt, f[x]);
    return rlt;
}

priority_queue <lec> pq;

bool check() {
    sort(l, l + n, cmp); m = 0;
    while (!pq.empty()) pq.pop();
    for (int i = 0; i < n; i ++) x[++m] = l[i].sb;
    sort(x + 1, x + m + 1);
    m = unique(x + 1, x + m + 1) - x - 1;
    for (int i = 1; i <= m; i ++) f[i] = 0;
    for (int i = 0; i < n; i ++) {
        while (!pq.empty()) {
            lec L = pq.top();
            if (L.ea >= l[i].sa) break; pq.pop();
            update(lower_bound(x + 1, x + m + 1, L.sb) - x, L.eb);
        }
        if (query(upper_bound(x + 1, x + m + 1, l[i].eb) - x - 1) >= l[i].sb) return 0;
        pq.push(l[i]);
    }
    return 1;
}

bool solve() {
    if (!check()) return 0;
    for (int i = 0; i < n; i ++) swap(l[i].sa, l[i].sb), swap(l[i].ea, l[i].eb);
    if (!check()) return 0;
    return 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) l[i].in();
    if (solve()) puts("YES");
    else puts("NO");

    return 0;
}