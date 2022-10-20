#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;

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

char s[105], t[10];
int cnt[26];

void solve() {
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    mset(cnt, 0);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    if (t[1] == 'a' && t[2] == 'b' && t[3] == 'c' && cnt[0] && cnt[1] && cnt[2]) {
        for (int i = 1; i <= cnt[0]; ++i) {
            putchar('a');
        }
        for (int i = 1; i <= cnt[2]; ++i) {
            putchar('c');
        }
        for (int i = 1; i <= cnt[1]; ++i) {
            putchar('b');
        }
        for (int i = 3; i < 26; ++i) {
            for (int j = 1; j <= cnt[i]; ++j) {
                putchar('a' + i);
            }
        }
    } else {
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= cnt[i]; ++j) {
                putchar('a' + i);
            }
        }
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