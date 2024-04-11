#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const LL INF = 0x3f3f3f3f3f3f3f3f;

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

template <typename T> inline void cmin(T &x, T y) {
    if (x > y) x = y;
}

int n, m, k, tot;
LL H[MAXN], dmg[MAXN], dp[MAXN];

struct Node {
    int pos, id;
    Node() {}
    Node(int _pos, int _id): pos(_pos), id(_id) {}
    bool operator < (const Node &rhs) const {
        return pos < rhs.pos;
    }
};
vector<Node> p[MAXN];

void solve() {
    read(n); read(m); read(k);
    tot = 0;
    for (int i = 1; i <= n; ++i) {
        p[i].clear();
        read(dmg[i]);
    }
    for (int i = 1, a, b, c, d, h; i <= k; ++i) {
        read(a); read(b); read(c); read(d); read(h);
        p[a].push_back(Node(b, ++tot));
        p[c].push_back(Node(d, ++tot));
        H[tot - 1] = h;
    }
    p[1].push_back(Node(1, ++tot));
    H[tot] = -INF;
    p[n].push_back(Node(m, ++tot));
    fill(dp + 1, dp + tot +1, INF);
    dp[tot - 1] = 0;
    for (int i = 1; i <= n; ++i) {
        sort(p[i].begin(), p[i].end());
        int sz = p[i].size();
        for (int j = 1; j < sz; ++j) {
            cmin(dp[p[i][j].id], dp[p[i][j - 1].id] + dmg[i] * (p[i][j].pos - p[i][j - 1].pos));
        }
        for (int j = sz - 2; j >= 0; --j) {
            cmin(dp[p[i][j].id], dp[p[i][j + 1].id] + dmg[i] * (p[i][j + 1].pos - p[i][j].pos));
        }
        for (auto q : p[i]) {
            if (q.id & 1) {
                cmin(dp[q.id + 1], dp[q.id] - H[q.id]);
            }
        }
    }
    if (dp[tot] > 1e17) {
        puts("NO ESCAPE");
    } else {
        printf("%lld\n", dp[tot]);
    }
}

int main() {
	int T; read(T);
	while (T--) {
        solve();
	}
	return 0;
}