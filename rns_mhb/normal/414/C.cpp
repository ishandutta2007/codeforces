#include <bits/stdc++.h>
using namespace std;
#define N (1<<21)
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

int n, m, k, cur, a[N], num[N], fi[N+1];
ll bi[21], sm[21];

bool cmp(int i, int j) {
    if (a[i] == a[j]) return i < j;
    return a[i] < a[j];
}

bool cmp2(int i, int j) {
    if (a[i] == a[j]) return i > j;
    return a[i] < a[j];
}

void add(int i, int  b) {
    int id = i + k, t;
    while (id > 1) {
        fi[id] ++;
        if (id & 1 ^ b) {
            if (b) bi[30-__builtin_clz(id)] += fi[id+1];
            else sm[30-__builtin_clz(id)] += fi[id-1];
        }
        id >>= 1;
    }
}

void modify() {
    int q; ll ans = 0;
    scanf("%d", &q);
    for (int i = 1; i <= q; i ++) swap(bi[n-i], sm[n-i]);
    for (int i = 0; i < n; i ++) ans += bi[i];
    printf("%I64d\n", ans);
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n); k = (1 << n);
    int i, j;
    for (i = 0; i < k; i ++) scanf("%d", &a[i]), num[i] = i;
    sort(num, num + k, cmp);
    for (i = 0; i < k; i ++) add(num[i], 1);
    for (i = j = 0; i <= k; i ++) {
        if (i == k || a[num[i]] != a[num[j]]) {
            for (int l = 0; l < i - j; l ++)
                fi[l] = num[j+l];
            for (int l = 0; l < i - j; l ++)
                num[j+l] = fi[i-j-1-l];
            j = i;
        }
    }
    memset(fi, 0, sizeof fi);
    for (i = 0; i < k; i ++) add(num[i], 0);
    scanf("%d", &m);
    while (m --) modify();

    return 0;
}