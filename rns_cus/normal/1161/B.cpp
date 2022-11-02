#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, m, a[N], b[N];

typedef pair <int, int> pii;

map <pii, bool> mp;

bool solve(int k) {
    if (k == n) return 0;
    for (int i = 0; i < m; i ++) {
        int x = a[i] + k, y = b[i] + k;
        if (x > n) x -= n;
        if (y > n) y -= n;
        if (x > y) swap(x, y);
        if (!mp[pii(x, y)]) return 0;
    }
    return 1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i ++) {
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] > b[i]) swap(a[i], b[i]);
        mp[pii(a[i], b[i])] = 1;
    }
    bool fg = 0;
    for (int k = 1; k * k <= n; k ++) {
        if (n % k) continue;
        if (solve(k) || solve(n / k)) {fg = 1; break;}
    }
    puts(fg ? "Yes" : "No");

    return 0;
}