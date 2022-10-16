// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, d[N], t;

char s[N];
 
int inline get(int c) {
    t = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] - 'a' != c) d[++t] = i;
        else sum++;
    }
    if (t == 0) return 0;
    for (int i = 1; i <= t / 2; i++)
        if (s[d[i]] != s[d[t - i + 1]]) return 2e9;
    sum -= 2 * min(d[1] - 1, n - d[t]);
    for (int i = 1; i < t / 2; i++) {
        sum -= 2 * min(d[i + 1] - d[i] - 1, d[t - i + 1] - d[t - i] - 1);
    }
    if (t % 2 == 0) sum -= d[t / 2 + 1] - d[t / 2] - 1;
    else if (t > 1) sum -= 2 * min(d[t / 2 + 1] - d[t / 2] - 1, d[t / 2 + 2] - d[t / 2 + 1] - 1);
    return sum;
}

int main() {
    int T; read(T);
    while (T--) {
        read(n); scanf("%s", s + 1);
        int ans = 2e9;
        for (int i = 0; i < 26; i++)
            chkMin(ans, get(i));
        if (ans == 2e9) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}