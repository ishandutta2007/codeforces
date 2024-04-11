#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 1000000007
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int q, n, f, inv[N], fac[N], p[6];

void Euclid(int a, int b, int &x, int &y) {
    if (!a) x = 0, y = 1;
    else {
        int q = b / a, r = b % a;
        Euclid(r, a, y, x);
        x -= q * y;
    }
}

int cal(int n, int m) {
    if (m > n) return 0;
    return 1ll * fac[n-1] * inv[m-1] % inf * inv[n-m] % inf;
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    fac[0] = 1;
    for (int i = 1; i < N; i ++) fac[i] = 1ll * fac[i-1] * i % inf;
    int x, y;
    Euclid(fac[N-1], inf, x, y);
    inv[N-1] = x;
    for (int i = N - 1; i > 0; i --) inv[i-1] = 1ll * inv[i] * i % inf;
    scanf("%d", &q);
    while (q --) {
        scanf("%d %d", &n, &f);
        x = 0, y = n;
        for (int i = 2; i <= sqrt(y); i ++) {
            if (y % i) continue;
            p[x++] = i;
            while (y % i == 0) y /= i;
        }
        if (y > 1) p[x++] = y;
        y = 0;
        for (int i = 0; i < (1 << x); i ++) {
            int tmp = n, cnt = 0;
            for (int j = 0; j < x; j ++)
                if (i & (1 << j)) cnt ++, tmp /= p[j];
            if (cnt & 1) y = (y - cal(tmp, f) + inf) % inf;
            else y = (y + cal(tmp, f)) % inf;
        }
        printf("%d\n", y);
    }


    return 0;
}