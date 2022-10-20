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

int n;
map<int, int> cnt;

void solve() {
    read(n);
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
        int a; read(a);
        ++cnt[a];
    }
    int ans1 = 0, ans2 = 0;
    for (auto pr : cnt) {
        if (pr.second >= 2) {
            ++ans1;
        } else {
            ++ans2;
        }
    }
    printf("%d\n", ans1 + ((ans2 + 1) / 2));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}