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
int n, m, nm, ans1[MAXN], ans2[MAXN];

void solve() {
    read(n); read(m);
    nm = n * m;
    scanf("%s", s + 1);
    for (int i = 1; i <= nm; ++i) {
        ans1[i] = ans2[i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= nm; j += m) {
            if (s[j] == '1') {
                ++ans1[j];
                break;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= nm; ++i) {
        if (s[i] == '1') {
            ++cnt;
        }
        if (i > m && s[i - m] == '1') {
            --cnt;
        }
        if (cnt) {
            ++ans2[i];
        }
    }
    for (int i = 1; i <= nm; ++i) {
        ans1[i] += ans1[i - 1];
        if (i > m) ans2[i] += ans2[i - m];
        printf("%d ", ans1[i] + ans2[i]);
    }
    printf("\n");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}