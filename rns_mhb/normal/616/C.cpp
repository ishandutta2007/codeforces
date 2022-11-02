#include <bits/stdc++.h>
using namespace std;
#define N 1100000
#define inf 1000000000
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

int n, m, p[N], sz[N];
char s[N];

void makeset(int x) {
    p[x] = x, sz[x] = 1;
}

int findroot(int x) {
    if (p[x] != x)
        p[x] = findroot(p[x]);
    return p[x];
}

void link(int x, int y) {
    x = findroot(x), y = findroot(y);
    if (x == y) return;
    if (sz[x] < sz[y])
        p[x] = y, sz[y] += sz[x];
    else p[y] = x, sz[x] += sz[y];
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i ++) gets(s + i * (m + 1));
    for (int i = 0; i < N; i ++) {
        if (s[i] != '.') continue;
        makeset(i);
        if (s[i-1] == '.') link(i - 1, i);
        if (s[i-m-1] == '.') link(i - m - 1, i);
    }
    for (int i = 0; i < N; i ++) {
        if (s[i] != '*') continue;
        int a[4], sum = 0;
        a[0] = findroot(i - 1), a[1] = findroot(i + 1), a[2] = findroot(i - m - 1), a[3] = findroot(i + m + 1);
        for (int j = 0; j < 4; j ++) {
            for (int k = 0; k < j; k ++)
                if (a[k] == a[j]) {sum -= sz[a[j]]; break;}
            sum += sz[a[j]];
        }
        sum ++, s[i] = sum % 10 + '0';
    }
    for (int i = 1; i <= n; i ++) puts(s + i * (m + 1));

    return 0;
}