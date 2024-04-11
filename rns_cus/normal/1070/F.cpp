#include <bits/stdc++.h>
using namespace std;
#define N 400010
#define gc getchar
#define pc putchar
#define pb push_back
#define X first
#define Y second
#define Mod(x) (((x) % mod + mod) % mod)
#define all(x) x.begin(), x.end()

typedef pair <int, int> pii;
typedef long long ll;

const int inf = 1e9;
const int mod = 1e9 + 7;
const ll INF = 1e18;
const double ep = 1e-7;
const double pi = 3.14159265358979323846264338327950288L;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, ans, tmp, sz[5];
vector <int> vec[5];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0, s, x; i < n; i ++) {
        scanf("%d %d", &s, &x);
        if (s == 11) vec[0].pb(x);
        if (s == 10) vec[1].pb(x);
        if (s == 1) vec[2].pb(x);
        if (s == 0) vec[3].pb(x);
    }
    for (int i = 0; i < 4; i ++) sort(all(vec[i]), greater <int> () ), sz[i] = vec[i].size();

    tmp = 0;
    int d = sz[0] - abs(sz[1] - sz[2]);
    if (d >= 0) {
        for (int i = 1; i < 3; i ++)
            for (int j = 0; j < sz[i]; j ++) tmp += vec[i][j];
        for (int j = 0; j < sz[3] && j < d; j ++) tmp += vec[3][j];
        chkmax(ans, tmp);
    }

    for (int i = 1; i <= 2; i ++) {
        int j = 3 - i;
        tmp = 0;
        int sum = sz[0] + sz[j];
        if (sum > sz[i] + sz[3]) continue;
        if (sz[i] < sz[j]) continue;
        for (int x = 0; x < sz[j]; x ++) tmp += vec[j][x];
        int k = max(sum - sz[i], 0);
        for (int x = 0; x < sz[i] && x < sum; x ++) tmp += vec[i][x];
        for (int x = 0; x < k; x ++) tmp += vec[3][x];
        chkmax(ans, tmp);
        for (int x = k; x < sz[3] && x < sum; x ++) {
            if (sum - 1 - x < sz[j]) break;
            tmp += vec[3][x] - vec[i][sum-1-x];
            chkmax(ans, tmp);
        }
    }
    for (int i = 0; i < sz[0]; i ++) ans += vec[0][i];
    printf("%d\n", ans);

    return 0;
}