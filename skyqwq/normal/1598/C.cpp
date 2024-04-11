// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n;

LL a[N];

map<LL, int> M;
 
int main() {
    int T; read(T);
    while (T--) {
        LL ans = 0;
        M.clear(); read(n); LL s = 0;
        for (int i = 1; i <= n; i++) {
            read(a[i]), s += a[i];
        }
        for (int i = 1; i <= n; i++) {
            ans += M[2 * s - n * a[i]];
            M[n * a[i]]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}