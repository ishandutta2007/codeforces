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

int n;
map<int, int> mp;

void solve() {
    read(n);
    mp.clear();
    for (int i = 1; i <= n; ++i) {
        int x; read(x);
        ++mp[x - i + 1];
        ++mp[x - i];
        ++mp[x - i + 2];
    }
    for (auto p : mp) {
        if (p.second == n) {
            puts("YES");
            return;
        }
    }
    puts("NO");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}