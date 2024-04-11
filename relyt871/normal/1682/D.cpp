#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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

char s[MAXN << 1];
int n;

void solve() {
    read(n);
    scanf("%s", s + 1);
    int odd = 0;
    for (int i = 1; i <= n; ++i) {
        odd += (s[i] == '1');
        s[n + i] = s[i];
    }
    if (odd == 0 || (odd & 1)) {
        puts("NO");
        return;
    }
    puts("YES");
    if (odd == n) {
        for (int i = 2; i <= n; ++i) {
            printf("%d %d\n", 1, i);
        }
        return;
    }
    int p = -1;
    s[0] = s[n];
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '0' && s[i - 1] == '1') {
            p = i;
            break;
        }
    }
    int lst = p;
    for (int i = p + 1; i < p + n; ++i) {
        int j = (i <= n? i : i - n);
        printf("%d %d\n", lst, j);
        if (s[i] == '0') {
            lst = j;
        } else {
            lst = p;
        }
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}