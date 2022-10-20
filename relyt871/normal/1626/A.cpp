#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 505;

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

char s[N];

void solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; ++i) {
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