#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 505;
const int INF = 1e9;

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
int rcnt[N][N], ccnt[N][N];
int dis[N][N], vis[N][N];
priority_queue< pair<int, pair<int, int>> > pq;

void solve() {
    read(n); read(k);
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            rcnt[i][j] = ccnt[i][j] = 0;
        }
    }
    for (int i = 1, r1, c1, r2, c2; i <= n; ++i) {
        read(r1); read(c1); read(r2); read(c2);
        if (r1 == r2) {
            if (c1 > c2) swap(c1, c2);
            ++ccnt[r1][c1];
            ++ccnt[k - r1 + 1][k - c1];
        } else {
            if (r1 > r2) swap(r1, r2);
            ++rcnt[r1][c1];
            ++rcnt[k - r1][k - c1 + 1];
        }
    }

    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            dis[i][j] = INF;
            vis[i][j] = 0;
        }
    }
    dis[0][0] = 0;
    pq.push(MP(0, MP(0, 0)));
    while (!pq.empty()) {
        int x = pq.top().se.fi, y = pq.top().se.se;
        pq.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        if (x > 0 && dis[x - 1][y] > dis[x][y] + ccnt[x][y]) {
            dis[x - 1][y] = dis[x][y] + ccnt[x][y];
            pq.push(MP(-dis[x - 1][y], MP(x - 1, y)));
        }
        if (x < k && dis[x + 1][y] > dis[x][y] + ccnt[x + 1][y]) {
            dis[x + 1][y] = dis[x][y] + ccnt[x + 1][y];
            pq.push(MP(-dis[x + 1][y], MP(x + 1, y)));
        }
        if (y > 0 && dis[x][y - 1] > dis[x][y] + rcnt[x][y]) {
            dis[x][y - 1] = dis[x][y] + rcnt[x][y];
            pq.push(MP(-dis[x][y - 1], MP(x, y - 1)));
        }
        if (y < k && dis[x][y + 1] > dis[x][y] + rcnt[x][y + 1]) {
            dis[x][y + 1] = dis[x][y] + rcnt[x][y + 1];
            pq.push(MP(-dis[x][y + 1], MP(x, y + 1)));
        }
    }
    printf("%d\n", n - dis[k / 2][k / 2]);
}

int main() {
	int T; read(T);
	while (T--) {
        solve();
	}
	return 0;
}