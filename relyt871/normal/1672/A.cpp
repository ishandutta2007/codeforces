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

void solve() {
    int n; read(n);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int a; read(a);
        sum += a - 1;
    }
    puts((sum & 1)? "errorgorn" : "maomao90");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}