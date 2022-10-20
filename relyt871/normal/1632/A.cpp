#include<bits/stdc++.h>
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

int n;
char s[MAXN];

void solve() {
    read(n);
    scanf("%s", s + 1);
    if (n <= 1) {
        puts("YES");
        return;
    }
    if (n == 2) {
        puts((s[1] != s[2])? "YES" : "NO");
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