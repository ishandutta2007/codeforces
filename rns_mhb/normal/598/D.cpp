#include <bits/stdc++.h>
using namespace std;
#define N 1000100
#define M 1010
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

int n, m, k, rt[N], hz[N], ed[N];
char s[M][M];

void init() {
    for (int i = 1; i < N; i ++) rt[i] = i, hz[i] = 1;
}
int find_root(int h) {
    return h == rt[h] ? h : rt[h] = find_root(rt[h]);
}

void link(int x, int y) {
    x = find_root(x), y = find_root(y);
    if (x == y) {
        ed[x] ++;
        return;
    }
    if (hz[x] > hz[y]) swap(x, y);
    rt[x] = y, hz[y] += hz[x], ed[y] += ed[x] + 1;
}

inline id(int x, int y) {
    return x * m + y;
}

int main() {
    init();
    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 0; i < n; i ++) {
        gets(s[i]);
        for (int j = 0; j < m; j ++) {
            if (s[i][j] == '.') {
                if (s[i-1][j] == '.') link(id(i, j), id(i - 1, j));
                if (s[i][j-1] == '.') link(id(i, j), id(i, j - 1));
            }
        }
    }
    while (k --) {
        int x, y, u;
        scanf("%d %d", &x, &y);
        u = find_root(id(x - 1, y - 1));
        printf("%d\n", 4 * hz[u] - 2 * ed[u]);
    }

    return 0;
}