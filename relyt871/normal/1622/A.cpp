#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 500005;

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

void solve() {
    int a, b, c;
    read(a); read(b); read(c);
    if (a == b + c || b == a + c || c == a + b) {
        puts("YES");
        return;
    }
    if ((a == b && c % 2 == 0) || (b == c && a % 2 == 0) || (c == a && b % 2 == 0)) {
        puts("YES");
        return;
    }
    puts("NO");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}