#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

set <int> s;
int t[N];
int i1[N], i2[N], inv[N];
int a[N], b[N], n, x, ost, z, l, r, m;
vector <int> es[N];
int ans[N];

void add(int v, int l, int r, int p) {
    if (l + 1 == r) {
        t[v] = 1;
        return;
    }
    int m = (l + r) / 2;
    if (p < m) add(v * 2 + 1, l, m, p);
    else add(v * 2 + 2, m, r, p);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int sum(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l + r) / 2;
    return sum(v * 2 + 1, l, m, L, R) + sum(v * 2 + 2, m, r, L, R);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        i1[i] = sum(0, 0, n, 0, a[i]);
        add(0, 0, n, a[i]);
    }

    for (int i = 0; i < N; i++) t[i] = 0;
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    for (int i = n - 1; i >= 0; i--) {
        i2[i] = sum(0, 0, n, 0, b[i]);
        add(0, 0, n, b[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        z = i1[i] + i2[i] + ost;
        inv[i] = z % (n - i);
        ost = z / (n - i);
    }


    for (int i = 0; i < N; i++) t[i] = 0;

    for (int i = 0; i < n; i++) {
        l = 0;
        r = n;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (m - sum(0, 0, n, 0, m) <= inv[i])
                l = m;
            else
                r = m;
        }
        printf("%d ", l);
        add(0, 0, n, l);
    }

    return 0;
}