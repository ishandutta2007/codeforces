#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

int n, q, tot, root[MAXN], ch[2][MAXN * 32], siz[MAXN * 32];
int m, rx[100], ry[100];

void Insert(int &rt, int pre, int x, int d) {
    rt = ++tot;
    siz[rt] = siz[pre] + 1;
    if (d < 0) return;
    ch[0][rt] = ch[0][pre];
    ch[1][rt] = ch[1][pre];
    int t = ((x >> d) & 1);
    Insert(ch[t][rt], ch[t][pre], x, d - 1);
}

int Query(int x, int y, int d) {
    if (d < 0) return 0;
    int lsiz = siz[ch[0][y]] - siz[ch[0][x]];
    for (int i = 1; i <= m; ++i) {
        lsiz += siz[ch[0][ry[i]]] - siz[ch[0][rx[i]]];
    }
    if (lsiz >= 2) {
        for (int i = 1; i <= m; ++i) {
            rx[i] = ch[0][rx[i]];
            ry[i] = ch[0][ry[i]];
        }
        return Query(ch[0][x], ch[0][y], d - 1);
    } else {
        for (int i = 1; i <= m; ++i) {
            if (siz[ch[0][ry[i]]] - siz[ch[0][rx[i]]]) {
                rx[i] = ch[0][rx[i]];
                ry[i] = ch[0][ry[i]];
            } else {
                rx[i] = ch[1][rx[i]];
                ry[i] = ch[1][ry[i]];
            }
        }
        if (siz[ch[0][y]] - siz[ch[0][x]]) {
            rx[++m] = ch[0][x];
            ry[m] = ch[0][y];
        }
        return (1 << d) + Query(ch[1][x], ch[1][y], d - 1);
    }
}

void solve() {
    for (int i = 1; i <= tot; ++i) {
        ch[0][i] = ch[1][i] = siz[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        root[i] = 0;
    }
    tot = 0;
    read(n);
    for (int i = 1; i <= n; ++i) {
        int x; read(x);
        Insert(root[i], root[i - 1], x, 29);
    }
    read(q);
    while (q--){
        int l, r;
        read(l); read(r);
        m = 0;
        printf("%d\n", Query(root[l - 1], root[r], 29));
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}