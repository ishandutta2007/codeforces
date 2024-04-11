#include <bits/stdc++.h>
using namespace std;
#define N 24
#define inf 1000000007
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

int n, f[1<<N], i, j;
char c;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d\n", &n);
    for (i = 0; i < n; i ++) {
        while ((c = gc()) > 96) j |= 1 << c - 97;
        f[j] ++, j = 0;
    }
    for (i = 0; i < N; i ++)
        for (j = 0; j < 1 << N; j ++)
            if (j >> i & 1) f[j] += f[j^1<<i];
    for (i = j = 0; i < 1 << N; i ++) j ^= (n - f[i]) * (n - f[i]);
    printf("%d\n", j);

    return 0;
}