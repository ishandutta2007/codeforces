#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1000005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, k, f[MAXN];
char s[MAXN];

void solve() {
    read(n); read(k);
    scanf("%s", s + 1);
    int cnt = k;
    for (int i = 1; i <= n; ++i) {
        if (i == n) {
            f[i] = cnt;
            if ((k - cnt) & 1) {
                if (s[i] == '1') s[i] = '0';
                else s[i] = '1';
            }
            break;
        }
        if (s[i] == '1') {
            if (k & 1) {
                if (cnt) {
                    f[i] = 1;
                    --cnt;
                } else {
                    f[i] = 0;
                    s[i] = '0';
                }
            } else {
                f[i] = 0;
            }
        } else {
            if (!(k & 1)) {
                if (cnt) {
                    f[i] = 1;
                    --cnt;
                    s[i] = '1';
                } else {
                    f[i] = 0;
                    s[i] = '0';
                }
            } else {
                f[i] = 0;
                s[i] = '1';
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        putchar(s[i]);
    }
    puts("");
    for (int i = 1; i <= n; ++i) {
        printf("%d ", f[i]);
    }
    printf("\n");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}