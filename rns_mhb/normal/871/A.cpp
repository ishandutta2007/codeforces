#include <bits/stdc++.h>
using namespace std;
#define N 200050
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

int t, n;

int calc(int n) {
    if (n % 2 == 0 && n > 2) return n / 4;
    if (n == 9) return 1;
    if (n % 2 == 1 && n > 9) return calc(n - 9) + 1;
    return -inf;
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &t);
    while (t --) scanf("%d", &n), printf("%d\n", max(calc(n), -1));

    return 0;
}