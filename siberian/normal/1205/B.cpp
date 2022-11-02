#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXBIT = 100;

int n;

vector<int> cnt[MAXBIT];

void add(int x, int i) {
	int pos = 0;
	while (x) {
		if (x % 2 == 1) {
			cnt[pos].push_back(i);
		}
		x /= 2;
		pos++;
	}
}

void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		add(x, i);
	}
}
const int MAXN = 1e5 + 10;
vector<int> g[MAXN];

int bfs(int v) {
	vector<bool> used(MAXN, false);
	vector<int> dist(MAXN, 1e9);
	deque<int> q;
	q.push_back(v);
	used[v] = true;
	dist[v] = 0;
	while (!q.empty()) {
		int v = q[0];
		q.pop_front();
		for (auto i : g[v]) {
			if (used[i] && dist[i] < dist[v]) continue;
			if (used[i]) {
				return dist[i] + dist[v] + 1;
			}
			used[i] = true;
			dist[i] = dist[v] + 1;
			q.push_back(i);
		}
	}
	return 1e9;
}

int solve() {
	int ans = 1e9;
	for (int i = 0; i < MAXN; i++) {
		if (!g[i].empty())
			chkmin(ans, bfs(i));
	}
	if (ans == (int) 1e9)
		ans = -1;
	return ans;
}

int ans;

void run() {
	for (int i = 0; i < MAXBIT; i++) {
		if (cnt[i].size() >= 3) {
			cout << 3;
			exit(0);
		}
	}

	set<pair <int, int> > ed;
	for (int i = 0; i < MAXBIT; i++) {
		if (cnt[i].size() == 2) {
			ed.insert({min(cnt[i][0], cnt[i][1]), max(cnt[i][0], cnt[i][1])});
		}
	}

	for (auto i : ed) {
		int v = i.first;
		int u = i.second;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	ans = solve();
}

void write() {
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