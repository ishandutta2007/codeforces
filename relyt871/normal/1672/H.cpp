#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
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
int n, q, c[2][MAXN];

void solve() {
    read(n); read(q);
    scanf("%s", s + 1);
    c[0][1] = c[1][1] = 0;
    for (int i = 2; i <= n; ++i) {
        c[0][i] = c[0][i - 1] + (s[i] == '0' && s[i - 1] == '0');
        c[1][i] = c[1][i - 1] + (s[i] == '1' && s[i - 1] == '1');
    }
    while (q--) {
        int l, r;
        read(l); read(r);
        printf("%d\n", 1 + max(c[0][r] - c[0][l], c[1][r] - c[1][l]));
    }
}

int main() {
    solve();
    return 0;
}