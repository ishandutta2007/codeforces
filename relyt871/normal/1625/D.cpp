#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 300005;
const int MAXM = MAXN * 32;

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

int n, k;
int root, tot, ch[MAXM][2], id[MAXM], ans[MAXN];

void Insert(int &rt, int x, int d, int i) {
    if (!rt) rt = ++tot;
    if (d < 0) {
        id[rt] = i;
        return;
    }
    Insert(ch[rt][(x >> d) & 1], x, d - 1, i);
}

void Any(int rt, int d) {
    if (d < 0) {
        ans[id[rt]] = 1;
        return;
    }
    if (ch[rt][0]) Any(ch[rt][0], d - 1);
    else Any(ch[rt][1], d - 1);
}

bool DFS2(int x, int y, int d) {
    if (!x || !y) return 0;
    if (d < 0) {
        ans[id[x]] = ans[id[y]] = 1;
        return 1;
    }
    if ((k >> d) & 1) {
        if (DFS2(ch[x][0], ch[y][1], d - 1)) return 1;
        if (DFS2(ch[x][1], ch[y][0], d - 1)) return 1;
        return 0;
    } else {
        if (ch[x][0] && ch[y][1]) {
            Any(ch[x][0], d - 1);
            Any(ch[y][1], d - 1);
            return 1;
        }
        if (ch[x][1] && ch[y][0]) {
            Any(ch[x][1], d - 1);
            Any(ch[y][0], d - 1);
            return 1;
        }
        if (DFS2(ch[x][0], ch[y][0], d - 1)) return 1;
        if (DFS2(ch[x][1], ch[y][1], d - 1)) return 1;
        return 0;
    }
}

void DFS(int rt, int d) {
    if (!rt) return;
    if (d < 0) {
        ans[id[rt]] = 1;
        return;
    }
    if ((k >> d) & 1) {
        if (!ch[rt][1]) Any(ch[rt][0], d - 1);
        else if (!ch[rt][0]) Any(ch[rt][1], d - 1);
        else if (!DFS2(ch[rt][0], ch[rt][1], d - 1)) {
            Any(ch[rt][0], d - 1);
        }
        return;
    }
    DFS(ch[rt][0], d - 1);
    DFS(ch[rt][1], d - 1);
}

void solve() {
    read(n); read(k);
    if (k == 0) {
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i) {
            printf("%d ", i);
        }
        return;
    }
    for (int i = 1, x; i <= n; ++i) {
        read(x);
        Insert(root, x, 29, i);
    }
    DFS(root, 29);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += ans[i];
    }
    if (cnt < 2) {
        printf("-1");
    } else {
        printf("%d\n", cnt);
        for (int i = 1; i <= n; ++i) {
            if (ans[i]) printf("%d ", i);
        }
    }
}

int main() {
    solve();
    return 0;
}