#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
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

LL ans;

LL Ask(LL a, LL b) {
    printf("? %lld %lld\n", a, b);
    fflush(stdout);
    LL ret;
    read(ret);
    //ret = __gcd(ans + a, ans + b);
    return ret;
}

void solve() {
    //read(ans);
    LL x = 0;
    for (int i = 0; i < 30; ++i) {
        LL a = (1LL << i) - x, b = (1LL << i) * 3 - x;
        LL d = Ask(a, b);
        if (d != (1LL << i)) {
            x |= (1LL << i);
        }
    }
    printf("! %lld\n", x);
    fflush(stdout);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}