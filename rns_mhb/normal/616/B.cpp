#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define gc getchar
#define pc putchar
#define pb push_back
#define X first
#define Y second
#define Mod(x) (((x) % mod + mod) % mod)
#define all(x) x.begin(), x.end()

const int inf = 1e9 + 7;
const double eps = 1e-7;
const double pi = 3.14159265358979323846264338327950288L;

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, m, tp, ans;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) {
        tp = inf;
        for (int j = 0, k; j < m; j ++)
            scanf("%d", &k), chkmin(tp, k);
        chkmax(ans, tp);
    }
    printf("%d\n", ans);

    return 0;
}