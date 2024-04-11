#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 1000000000
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

int n, m, maxi, d[N], h[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i ++)
        scanf("%d %d", &d[i], &h[i]);
    for (int i = 1; i < m; i ++) {
        if (abs(h[i] - h[i-1]) > d[i] - d[i-1]) {
            puts("IMPOSSIBLE");
            return 0;
        }
        else chkmax(maxi, (h[i-1] + h[i] + d[i] - d[i-1]) / 2);
    }
    chkmax(maxi, h[0] + d[0] - 1);
    chkmax(maxi, h[m-1] + n - d[m-1]);
    printf("%d\n", maxi);

    return 0;
}