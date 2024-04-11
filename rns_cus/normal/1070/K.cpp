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

int k, n, sum, a[N], s[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum += a[i];
    if (sum % k) return puts("No"), 0;
    sum /= k;
    int cnt = 0;
    for (int i = 1, j = 1; i <= n; i ++) {
        cnt += a[i];
        if (cnt >= sum) {
            if (cnt > sum) return puts("No"), 0;
            else s[j++] = i, cnt = 0;
        }
    }
    puts("Yes");
    for (int j = k; j; j --) s[j] -= s[j-1];
    for (int j = 1; j <= k; j ++) printf("%d%c", s[j], j < k ? ' ' : '\n');

    return 0;
}