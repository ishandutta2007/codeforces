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

const int N = 2e5 + 5;

int n, a[N], d[N], c[N], t, nc[N];
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]), c[a[i]]++;
        int p = 1, la = 1; t = 0;
        while (p <= n) {
            int me = 0;
            c[a[p]]--;
            nc[a[p]]++;
            while (nc[me]) me++;
            while (c[me]) {
                p++;
                c[a[p]]--;
                nc[a[p]]++;
                while (nc[me]) me++;
            }
            p++;
            d[++t] = me;
            for (int i = la; i < p; i++) nc[a[i]] = 0;
            la = p;
        }
        printf("%d\n", t);
        for (int i = 1; i <= t; i++) printf("%d ", d[i]);
        puts("");
        for (int i = 0; i <= n; i++) nc[i] = c[i] = 0;
    }
    return 0;
}