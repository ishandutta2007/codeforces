#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct segm{
	int l, r;
	segm() {}
	segm(int _l, int _r) {
		l = _l, r = _r;
	}
};

int n, k;
vector<segm> have;

void read() {
	cin >> n >> k;
	have.resize(k + 1);
	have[0] = {0, 0};
	for (int i = 1; i <= k; i++) {
		cin >> have[i].l >> have[i].r;
	}
}

const int MAXN = 5e5 + 10;
const int MAXK = 110;
int dp[2][MAXN][2];
const int INF = 1e9 + 10;
int ans;

void build() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < MAXN; j++)
			for (int t = 0; t < 2; t++)
				dp[i][j][t] = INF;
	dp[0][0][0] = 0;
}

deque<pair<int, int>> q;

void clear() {
	q.clear();
}

void add(int x, int id) {
	while (!q.empty() && q.back().first >= x)
		q.pop_back();
	q.push_back({x, id});
}

void del(int id) {
	if (q.front().second == id)
		q.pop_front();
}

int get() {
	if (q.empty()) return INF;
	return q.front().first;
}

void calc() {
	for (int i = 1; i <= k; i++) {
		int l, r;
		int len = have[i].r - have[i].l;
		int dist = have[i].l - have[i - 1].r;
		
		clear();
		l = 0, r = 0;
		for (int t = dist; t <= n; t++) {
			if (t - dist - len >= 0) {
				chkmin(dp[1][t][0], dp[0][t - dist - len][0]);
				chkmin(dp[1][t][1], dp[0][t - dist - len][0] + 1);
			}
			while (r <= n && r <= t - dist) {
				add(dp[0][r][0], r);
				r++;
			}			
			while (l < r && l < t - dist - len) {
				del(l);
				l++;
			} 
			chkmin(dp[1][t][0], get() + 2);
			chkmin(dp[1][t][1], get() + 1);
		}

		clear();
		l = 0, r = 0;
		for (int t = 0; t <= n; t++) {
			chkmin(dp[1][t][1], dp[0][t][1]);
			chkmin(dp[1][t][0], dp[0][t][1] + 1);
			while (r <= n && r < t) {
				add(dp[0][r][1], r);
				r++;
			}
			while (t > l + len) {
				del(l);
				l++;
			}
			chkmin(dp[1][t][0], get() + 1);
			chkmin(dp[1][t][1], get() + 2);
		}
		for (int t = 0; t <= n; t++) {
			for (int type = 0; type < 2; type++) {
				dp[0][t][type] = dp[1][t][type];
				dp[1][t][type] = INF;
			}
		}
	}
}

void make_ans() {
	ans = dp[0][n][1];
	if (n - (2 * n - have[k].r) >= 0)
		chkmin(ans, dp[0][n - (2 * n - have[k].r)][0]);
	if (ans == INF) {
		cout << "Hungry" << endl;
		exit(0);
	}
}

void run() {
	build();
	calc();
	make_ans();
}

void write() {
	cout << "Full" << endl;
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}