#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 500005;

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
int n, a[MAXN], ans[MAXN];

struct Node {
    int num, pos;
    Node() {}
    Node(int _num, int _pos): num(_num), pos(_pos) {}
    bool operator < (const Node &rhs) const {
        return num < rhs.num;
    }
} p[MAXN], q[MAXN];

void solve() {
    int t1 = 0, t2 = 0;
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1') {
            p[++t1] = Node(a[i], i);
        } else {
            q[++t2] = Node(a[i], i);
        }
    }
    sort(p + 1, p + t1 + 1);
    sort(q + 1, q + t2 + 1);
    for (int i = 1; i <= t2; ++i) {
        ans[q[i].pos] = i;
    }
    for (int i = 1; i <= t1; ++i) {
        ans[p[i].pos] = t2 + i;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
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