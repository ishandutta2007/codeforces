#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, q, a[N], b[N], l[N], r[N];
vector <int> st[N], ed[N];

int main() {
    ;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= q; i ++) l[i] = n + 1, r[i] = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (a[i]) l[a[i]] = min(l[a[i]], i), r[a[i]] = max(r[a[i]], i);
    }
    if (!r[q]) {
        int k;
        for (k = 1; k <= n; k ++) if (!a[k]) break;
        if (k > n) return puts("NO"), 0;
        l[q] = r[q] = k;
    }
    for (int i = 1; i < q; i ++) if (!r[i]) l[i] = l[i+1], r[i] = r[i+1];
    l[1] = 1, r[1] = n;
    for (int i = 1; i <= q; i ++) st[l[i]].push_back(i), ed[r[i]].push_back(i);
    set <int> S;
    for (int i = 1; i <= n; i ++) {
        for (auto u : st[i]) S.insert(u);
        b[i] = *(--S.end());
        if (a[i] && a[i] != b[i]) return puts("NO"), 0;
        for (auto u : ed[i]) S.erase(u);
    }
    puts("YES");
    for (int i = 1; i <= n; i ++) printf("%d ", b[i]);

    return 0;
}