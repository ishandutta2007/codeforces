#include <bits/stdc++.h>
using namespace std;
#define N 111
#define inf 1000000007
#define eps 1e-7
#define pi 3.14159265358979323846264338327950288L
#define gc getchar
#define pc putchar
#define pb push_back
#define X first
#define Y second
#define Mod(x) (((x) % mod + mod) % mod)
#define all(x) x.begin(), x.end()

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, m, mi, ma, s[N], h[N], id[N], a[N];
bool vis[N];
vector <int> vec;

bool solve(int i) {
    vec.clear();
    int cur = 0;
    for (int j = ma; j > i; j --) {
        if (id[j]) {
            if (h[id[j]] > cur) vec.pb(id[j]), cur = h[id[j]];
        }
        cur += a[j];
        if (cur < 0) return 0;
    }
    cur = 0;
    for (int j = mi; j <= i; j ++) {
        if (id[j]) {
            if (h[id[j]] > cur) vec.pb(id[j]), cur = h[id[j]];
        }
        cur += a[j];
        if (cur < 0) return 0;
    }
    printf("%d\n", i);
    int sz = vec.size();
    for (int j = 0; j < sz; j ++) vis[vec[j]] = 1;
    for (int j = sz - 1; j >= 0; j --) printf("%d ", vec[j]);
    for (int j = 1; j <= m; j ++) if (!vis[j]) printf("%d ", j);
    puts("");
    return 1;
}

int main() {
//    freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &m);
    mi = n, ma = 1;
    for (int i = 1; i <= m; i ++) scanf("%d %d", &s[i], &h[i]), id[s[i]] = i, chkmax(ma, s[i]), chkmin(mi, s[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = mi; i <= ma; i ++) if (solve(i)) return 0;
    puts("-1");

    return 0;
}