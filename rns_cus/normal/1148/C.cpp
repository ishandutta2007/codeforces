#include <bits/stdc++.h>
using namespace std;

#define N 300200

int n, m, p[N], id[N];
vector <pair <int, int> > vec;

void put(int x, int y) {
    vec.emplace_back(x, y);
    swap(p[x], p[y]);
    id[p[x]] = x;
    id[p[y]] = y;
}

void Swap(int x, int y) {
    if (x > y) swap(x, y);
    if (y <= m) {
        put(x, n);
        put(y, n);
        put(x, n);
    }
    else if (x > m) {
        put(x, 1);
        put(y, 1);
        put(x, 1);
    }
    else if (y - x >= m) put(x, y);
    else {
        put(x, n);
        put(y, 1);
        put(n, 1);
        put(y, 1);
        put(x, n);
    }
}

int main() {
    scanf("%d", &n); m = n / 2;
    for (int i = 1; i <= n; i ++) scanf("%d", &p[i]), id[p[i]] = i;
    for (int i = 1; i <= n; i ++) if (id[i] != i) Swap(id[i], i);
    int sz = vec.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++) printf("%d %d\n", vec[i].first, vec[i].second);
}