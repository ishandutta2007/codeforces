#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
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

int n, a[MAXN];
vector<int> ans;

void Construct(int l, int r) {
    for (int i = l; i <= r - 2; i += 2) {
        ans.push_back(i);
    }
    for (int i = r - 4; i >= l; i -= 2) {
        ans.push_back(i);
    }
}

void solve() {
    read(n);
    int xorsum = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        xorsum ^= a[i];
    }
    if (xorsum) {
        puts("NO");
        return;
    }
    ans.clear();
    if (n & 1) {
        Construct(1, n);
    } else {
        xorsum = 0;
        bool flag = 0;
        for (int i = 1; i <= n; ++i) {
            xorsum ^= a[i];
            if (!xorsum && (i & 1)) {
                Construct(1, i);
                Construct(i + 1, n);
                flag = 1;
                break;
            }
        }
        if (!flag) {
            puts("NO");
            return;
        }
    }
    puts("YES");
    printf("%d\n", ans.size());
    for (auto x : ans) {
        printf("%d ", x);
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