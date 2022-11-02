#include <bits/stdc++.h>
using namespace std;
#define N 200010
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

int n, m;
char s[N], t[N];

bool cmp() {
    int k = -1;
    for (int i = 0; i < n; i ++)
        if (s[i] == '*') k = i;
    if (k < 0) {
        if (n != m) return 0;
        for (int i = 0; i < n; i ++)
            if (s[i] != t[i]) return 0;
        return 1;
    }
    else {
        if (n > m + 1) return 0;
        for (int i = 0; i < k; i ++)
            if (s[i] != t[i]) return 0;
        for (int i = 1; i < n - k; i ++)
            if (s[n-i] != t[m-i]) return 0;
        return 1;
    }
}

int main() {
//    freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &m);
    scanf("%s %s", s, t);
    puts(cmp() ? "YES" : "NO");

    return 0;
}