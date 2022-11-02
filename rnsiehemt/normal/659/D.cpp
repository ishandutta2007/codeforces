#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, a, b, p, q, x, y, ans;

int get(int a, int b, int p, int q) {
    if (p > a) return 0;
    else if (q < b) return 1;
    else if (p < a) return 2;
    else {
        assert(q > b);
        return 3;
    }
}

int main() {
    scanf("%d%d%d%d%d", &n, &a, &b, &p, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &x, &y);
        int d = get(a, b, p, q);
        int e = get(p, q, x, y);
        if ((d+3)%4 == e) ans++;
        a = p; b = q;
        p = x; q = y;
    }
    printf("%d\n", ans);
}