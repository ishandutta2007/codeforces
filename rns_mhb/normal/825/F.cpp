#include <bits/stdc++.h>
using namespace std;
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}
const int inf = 0x3f3f3f3f;

#define N 8005

int ts;
char s[N], t[N];
int dp[N], l[N], p[N];

int n;

int expmod(int a, int b, int mod) {
    int res = 1;
    for ( ; b; b >>= 1) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
    }
    return res;
}

int main() {
    f0(i, 1, 10) l[i] = 1;
    f0(i, 10, 100) l[i] = 2;
    f0(i, 100, 1000) l[i] = 3;
    f0(i, 1000, N) l[i] = 4;
    scanf("%s", s + 1);
    int len = strlen(s+1), lst, us;
    f1(i, 1, len) {
        dp[i] = inf;
        ts = 0; lst = 0;
        f3(j, i, 1) {
            t[++ ts] = s[j];
            while (lst && t[ts] != t[lst + 1]) lst = p[lst];
            if (ts > 1 && t[ts] == t[lst + 1]) lst ++;
            p[ts] = lst;
            us = ts - p[ts];
            if (p[ts] > 0 && ts % us == 0) chkmin(dp[i], l[ts / us] + us + dp[j-1]);
            else chkmin(dp[i], 1 + ts + dp[j-1]);
        }
    }
    printf("%d\n", dp[len]);
	return 0;
}