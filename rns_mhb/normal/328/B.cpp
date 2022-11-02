#include <bits/stdc++.h>
using namespace std;
#define f0(i, a, b) for (int i = a; i < b; i ++)

template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

#define N 205

char s[N], t[N];
int g[20], h[20];

int main() {
    scanf("%s %s", s, t);
    int ls = strlen(s), lt = strlen(t);
    f0(i, 0, ls) g[s[i]-'0'] ++; g[2] += g[5], g[5] = 0, g[6] += g[9], g[9] = 0;
    f0(i, 0, lt) h[t[i]-'0'] ++; h[2] += h[5], h[5] = 0, h[6] += h[9], h[9] = 0;
    int ans = 10000000;
    f0(i, 0, 10) if (g[i]) chkmin(ans, h[i] / g[i]);
    printf("%d\n", ans);
	return 0;
}