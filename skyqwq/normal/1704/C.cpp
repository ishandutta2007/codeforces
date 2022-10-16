// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int M = 1e5 + 5;

int n, m, a[M], d[M], t;

int main() {
 	int T; read(T);
 	while (T--) {
 		read(n), read(m);
        for (int i = 1; i <= m; i++) read(a[i]);
        sort(a + 1, a + 1 + m);
        t = 0;
        for (int i = 1; i < m; i++) d[++t] = a[i + 1] - a[i] - 1;
        d[++t] = a[1] - a[m] + n - 1;
        sort(d + 1, d + 1 + t, greater<int>() );
        int c = 0;
        LL ans = 0;
        for (int i = 1; i <= t; i++) {
            if (c * 2 + 1 == d[i]) {
                ans += max(0, d[i] - 2 * c);
                c++;
                continue;
            }
            ans += max(0, d[i] - c - (c + 1));
            c += 2;
        }
        printf("%lld\n", n - ans);
 	}   
    return 0;
}