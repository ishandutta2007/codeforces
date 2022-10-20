#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 150005;

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
vector<int> pos[MAXN];

inline int Calc(int x, int y) {
    return x + n - y;
}

void solve() {
    read(n);
    for (int i = 1; i <= 150000; ++i) {
        pos[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        int x; read(x);
        pos[x].push_back(i);
    }
    int ans = -1;
    for (int i = 1; i <= 150000; ++i) {
        if (pos[i].size() > 1) {
            for (int j = 0; j < pos[i].size() - 1; ++j) {
                ans = max(ans, Calc(pos[i][j], pos[i][j + 1]));
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}