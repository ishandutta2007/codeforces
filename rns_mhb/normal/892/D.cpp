#include <bits/stdc++.h>
using namespace std;
#define N 30
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

int n, a[N], id[N], rk[N];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]), id[i] = i;
    sort(id, id + n, cmp);
    for (int i = 0; i < n; i ++) rk[id[i]] = i;
    for (int i = 0; i < n; i ++) printf("%d ", a[id[(rk[i]+1)%n]]);


    return 0;
}