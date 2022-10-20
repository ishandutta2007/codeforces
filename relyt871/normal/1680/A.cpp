#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 1000006;

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
    int l1, r1, l2, r2;
    read(l1); read(r1); read(l2); read(r2);
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if (r1 >= l2) {
        printf("%d\n", l2);
    } else {
        printf("%d\n", l1 + l2);
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}