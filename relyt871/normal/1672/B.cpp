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

char s[MAXN];

bool solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int pre = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'A') ++pre;
        else --pre;
        if (pre < 0) return 0;
    }
    if (s[n] == 'A') return 0;
    return 1;
}

int main() {
    int T; read(T);
    while (T--) {
        puts(solve()? "YES" : "NO");
    }
    return 0;
}