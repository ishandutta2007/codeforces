#include <bits/stdc++.h>
using namespace std;
#define N 100100
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

int n;
ll m, sum;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n);
    sum = m = 1ll * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
    m = m * (n - 5) / 6, sum += m;
    m = m * (n - 6) / 7, sum += m;
    printf("%I64d\n", sum);

    return 0;
}