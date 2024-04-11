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

void solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (s[i] - 'a' + 1);
    }
    if (n % 2 == 0) {
        printf("Alice %d\n", sum);
    } else {
        int sum2 = min(s[1] - 'a' + 1, s[n] - 'a' + 1);
        sum -= sum2;
        if (sum > sum2) {
            printf("Alice %d\n", sum - sum2);
        } else {
            printf("Bob %d\n", sum2 - sum);
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