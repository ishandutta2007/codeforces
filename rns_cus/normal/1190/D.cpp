#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, m, w[N], fen[N];
typedef pair <int, int> pii;
pii p[N];

void add(int x) {
    for (; x <= m; x += x & -x) fen[x] ++;
}

int query(int x) {
    int rlt = 0;
    for (; x; x -= x & -x) rlt += fen[x];
    return rlt;
}

set <int> S;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        swap(x, y); x = -x;
        p[i] = pii(x, y);
        w[++m] = y;
    }
    sort(p, p + n);
    sort(w + 1, w + m + 1);
    m = unique(w + 1, w + m + 1) - w - 1;
    for (int i = 0; i < n; i ++) p[i].second = lower_bound(w + 1, w + m + 1, p[i].second) - w;
    long long ans = 0;
    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && p[j].first == p[i].first; j ++) {
            int x = p[j].second;
            if (S.find(x) == S.end()) S.insert(x), add(x);
        }
        int sz = S.size();
        ans += 1ll * sz * (sz + 1) / 2;
        vector <int> tmp;
        for (int k = i; k < j; k ++) tmp.push_back(query(p[k].second));
        sz = tmp.size();
        for (int i = 1; i < sz; i ++) {
            int t = tmp[i] - tmp[i-1] - 1;
            ans -= 1ll * t * (t + 1) / 2;
        }
        int t = tmp[0] - 1;
        ans -= 1ll * t * (t + 1) / 2;
        t = S.size() - tmp[sz-1];
        ans -= 1ll * t * (t + 1) / 2;
    }
    printf("%I64d\n", ans);

    return 0;
}