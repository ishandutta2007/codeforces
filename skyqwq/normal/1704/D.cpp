// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

#define I __int128

int n, m;
I c[N], s[N];

int main() {
 	int T; read(T);
 	while (T--) {
 		read(n), read(m);
        for (int i = 1; i <= n; i++) {
            s[i] = 0;
            for (int j = 1; j <= m; j++) read(c[j]);
            for (int j = 1; j <= m; j++) c[j] += c[j - 1], s[i] += c[j];
        }
        int p = 1;
        for (int i = 2; i <= n; i++) if (s[i] < s[p]) p = i;
        int q = p == 1 ? 2 : 1;
        LL ans = s[q] - s[p];
        printf("%d %lld\n", p, ans);
 	}   
    return 0;
}