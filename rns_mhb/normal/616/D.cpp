#include <bits/stdc++.h>
using namespace std;
#define N 500100
#define inf 1000000000
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

int n, k, l, r, a[N], gas[2*N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    int i, j;
    scanf("%d %d", &n, &k); k ++;
    for (i = 0; i < n; i ++) scanf("%d", &a[i]);
    for (j = 0; j < n; j ++) {
        if (!gas[a[j]]) k --;
        if (!k) break;
        else gas[a[j]] ++;
    }
    if (j == n) printf("1 %d\n", n);
    else {
        l = 0, r = j;
        for (i = 0; i < n && j < n; i ++) {
            gas[a[i]] --;
            if (!gas[a[i]]) {
                gas[a[j++]] ++;
                while (j < n && gas[a[j]]) gas[a[j++]] ++;
                if (j - i > r - l + 1) r = j, l = i + 1;
            }
        }
        printf("%d %d\n", l + 1, r);
    }

    return 0;
}