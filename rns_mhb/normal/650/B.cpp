#include <bits/stdc++.h>
using namespace std;
#define N 500100
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back
#define mn(k) max(k, 0)

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, a, b, T, rdp[N], ldp[N], t[N];
char s[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d %d %d\n", &n, &a, &b, &T);
    gets(s);
    for (int i = 0; i < n; i ++)
        if (s[i] == 'w') t[i] = a + b + 1;
        else t[i] = a + 1;
    t[n] = t[0], s[n] = s[0]; T -= t[0] - a;
    if (T < 0) {puts("0"); return 0;}
    for (int i = 1; i <= n; i ++) rdp[i] = rdp[i-1] + t[i];
    for (int i = n - 1; i >= 0; i --) ldp[i] = ldp[i+1] + t[i];
    int maxi = 0;
    for (int i = 0; i <= n && ldp[n-i] <= T; i ++)
        chkmax(maxi, i + 1 + mn(lower_bound(rdp, rdp + n + 1, T - ldp[n-i] - a * i + 1) - rdp - 1));
    for (int i = 0; i <= n && rdp[i] <= T; i ++)
        chkmax(maxi, i + 1 + mn(ldp + n - lower_bound(ldp, ldp + n + 1, T - rdp[i] - a * i, greater <int>() )));
    chkmin(maxi, n);
    printf("%d\n", maxi);

    return 0;
}