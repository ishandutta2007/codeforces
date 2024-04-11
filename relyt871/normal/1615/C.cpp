#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 100005;
const int MAX = 1e8;

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
char a[MAXN], b[MAXN], c[MAXN];

void solve() {
    read(n);
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    bool all0 = 1, equ = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != b[i]) equ = 0;
        if (a[i] != '0') all0 = 0;
    }
    if (equ) {
        printf("0\n");
        return;
    }
    if (all0) {
        printf("-1\n");
        return;
    }
    int ans = MAX;
    int c01 = 0, c10 = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == '0' && b[i] == '1') ++c01;
        if (a[i] == '1' && b[i] == '0') ++c10;
    }
    if (c01 == c10) ans = min(ans, c01 + c10);
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == '1' && b[i] == '1') {
            p = i; break;
        }
    }
    if (p) {
        for (int i = 1; i <= n; ++i) {
            if (i == p) c[i] = a[i];
            else c[i] = (a[i] == '1'? '0' : '1');
        }
        c01 = c10 = 0;
        for (int i = 1; i <= n; ++i) {
            if (c[i] == '0' && b[i] == '1') ++c01;
            if (c[i] == '1' && b[i] == '0') ++c10;
        }
        if (c01 == c10) ans = min(ans, c01 + c10 + 1);
    }
    p = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == '1' && b[i] == '0') {
            p = i; break;
        }
    }
    if (p) {
        for (int i = 1; i <= n; ++i) {
            if (i == p) c[i] = a[i];
            else c[i] = (a[i] == '1'? '0' : '1');
        }
        c01 = c10 = 0;
        for (int i = 1; i <= n; ++i) {
            if (c[i] == '0' && b[i] == '1') ++c01;
            if (c[i] == '1' && b[i] == '0') ++c10;
        }
        if (c01 == c10) ans = min(ans, c01 + c10 + 1);
    }
    printf("%d\n", (ans == MAX)? -1 : ans);
}


int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}