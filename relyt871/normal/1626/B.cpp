#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

char s[MAXN];

void solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = n; i > 1; --i) {
        if (s[i] - '0' + s[i - 1] - '0' >= 10) {
            for (int j = 1; j < i - 1; ++j) {
                putchar(s[j]);
            }
            printf("%d", s[i] - '0' + s[i - 1] - '0');
            for (int j = i + 1; j <= n; ++j) {
                putchar(s[j]);
            }
            puts("");
            return;
        }
    }
    printf("%d", s[1] - '0' + s[2] - '0');
    for (int i = 3; i <= n; ++i) {
        putchar(s[i]);
    }
    puts("");
}

int main() {
	int T; read(T);
	while (T--) {
        solve();
	}
	return 0;
}