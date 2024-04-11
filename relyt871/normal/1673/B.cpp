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
int sum[26][MAXN];
int pre[MAXN], lst[26];

void solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    mset(lst, 0);
    bool same = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != s[1]) {
            same = 0;
        }
        for (int j = 0; j < 26; ++j) {
            sum[j][i] = sum[j][i - 1];
        }
        sum[s[i] - 'a'][i] += 1;
        if (lst[s[i] - 'a']) {
            pre[i] = lst[s[i] - 'a'];
        } else {
            pre[i] = 0;
        }
        lst[s[i] - 'a'] = i;
    }
    if (same) {
        puts("YES");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!pre[i]) continue;
        for (int j = 0; j < 26; ++j) {
            if (j != s[i] - 'a' && lst[j] && sum[j][i - 1] - sum[j][pre[i]] == 0) {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}