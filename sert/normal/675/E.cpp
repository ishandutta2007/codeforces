#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;

pair<int, int> t[N];

void add(int v, int l, int r, int p, int x) {
    if (l + 1 == r) {
        t[v] = make_pair(x, p);
        return;
    }
    int m = (l + r) / 2;
    if (p < m)
        add(v * 2 + 1, l, m, p, x);
    else
        add(v * 2 + 2, m, r, p, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

pair<int, int> mx(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r)
        return make_pair(-N, 41);
    if (L <= l && r <= R)
        return t[v];
    int m = (l + r) / 2;
    return max(mx(v * 2 + 1, l, m, L, R), mx(v * 2 + 2, m, r, L, R));
}

ll sum;
ll a[N];
int d[N];
int n, p;

int main() {

    scanf("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        scanf("%d", d + i);
        d[i]--;
    }

    for (int i = 0; i < N; i++)
        t[i] = make_pair(-1e9, 34);

    add(0, 0, n, n - 2, n - 1);
    sum = a[n - 2] = 1;

    for (int i = n - 3; i >= 0; i--) {
        p = mx(0, 0, n, i + 1, d[i] + 1).second;
        a[i] = p - i + a[p] + (n - d[i] - 1);
        sum += a[i];
        add(0, 0, n, i, d[i]);
    }

    printf("%I64d\n", sum);
}