#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

char s[N];
int a, b, t, n, pos, l, r, m, st;
ll p[N];

int tme(int l, int r) {
    return p[r] - p[l];
}

int cnt(int l, int r) {
    if (l > n || r <= n) exit(34);
    return tme(l, r) + (r - l - 1) * a + a * min(n - l, r - 1 - n);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d %d %d %d\n", &n, &a, &b, &t);
    gets(s);
    //puts(s);

    p[0] = 0;
    for (int i = 1; i <= n * 2; i++) {
        pos = (i - 1) % n;
        p[i] = p[i - 1] + 1 + (s[pos] == 'w' ? b : 0);
    }

    l = 0;
    r = n + 1;

    bool ok;
    int tt;

    while (r - l > 1) {
        m = (l + r) / 2;
        ok = false;
        for (int i = n + 1 - m; !ok && i + m <= n * 2 && i <= n; i++) {
            tt = cnt(i, i + m);
            if (tt <= t)
                ok = true;
        }
        if (ok)
            l = m;
        else
            r = m;
    }
    cout << l;



    return 0;
}