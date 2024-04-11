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

char s[100];

void solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int a = 1, b = 1;
    for (int i = 1, j; i <= n; i = j + 1) {
        for (j = i; j < n && s[j + 1] == s[i]; ++j);
        int len = j - i + 1;
        if (s[i] == 'a') {
            a &= (len > 1);
        } else {
            b &= (len > 1);
        }
    }
    puts((a && b)? "YES" : "NO");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}