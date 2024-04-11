#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 500005;
const int INF = 0x3f3f3f3f;

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

int a, b;

void solve() {
    read(a); read(b);
    int ans1 = INF, ans2 = INF;

    ans1 = 0;
    int c = a, d = b;
    while ((c | d) != d) {
        ++d;
        ++ans1;
    }
    if (c != d) {
        ++ans1;
    }

    if (a < b) {
        ans2 = 0;
        c = a, d = b;
        while ((c | d) != d) {
            ++c;
            ++ans2;
        }
        if (c != d) {
            ++ans2;
        }
    }

    printf("%d\n", min(ans1, ans2));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}