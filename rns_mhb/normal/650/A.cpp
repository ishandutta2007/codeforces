#include <bits/stdc++.h>
using namespace std;
#define N 200100
#define inf 1000000001
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, cur, t, cur2, t2;
ll ans;
pii p[N];

bool cmp(pii a, pii b) {
    return a.second < b.second;
}

ll com(int i) {
    return 1ll * i * (i - 1) / 2;
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d %d", &p[i].first, &p[i].second);
    sort(p, p + n, cmp); cur = inf;p[n] = pii(inf + 1, inf + 1);
    for (int i = 0; i <= n; i ++, t ++)
        if (cur != p[i].second) ans += com(t), t = 0, cur = p[i].second;
    sort(p, p + n); cur = inf, t = 0;
    for (int i = 0; i <= n; i ++, t ++, t2 ++) {
        if (cur != p[i].first) ans += com(t), t = 0, cur = p[i].first, cur2 = inf;
        if (cur2 != p[i].second) ans -= com(t2), t2 = 0, cur2 = p[i].second;
    }
    printf("%I64d\n", ans);


    return 0;
}