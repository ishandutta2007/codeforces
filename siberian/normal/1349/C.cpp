#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(), (x).end()
template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e3 + 10, MAXQ = 1e5 + 10;
int n, m, q;
char a[MAXN][MAXN];

struct event{
	int i, j, ind;
	ll t;
	event() {}
};

bool operator<(const event & a, const event & b) {
	return a.t < b.t;
}

event Q[MAXQ];
char ans[MAXQ];

void read() {
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> Q[i].i >> Q[i].j >> Q[i].t;
		Q[i].i--;
		Q[i].j--;
		Q[i].ind = i;
	}
	sort(Q, Q + q);
}

int pos = 0;
ll now = 0;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

short int used[MAXN][MAXN];
char get(int x, int y, ll it) {
	if (used[x][y] == -1) return a[x][y];
	if ((it - used[x][y]) % 2 == 0) return a[x][y];
	return 1 - (a[x][y] - '0') + '0';
}

pair<short int, short int> need[MAXN * MAXN], nxt_need[MAXN * MAXN];
int top1 = 0, top2 = 0;

void build() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			used[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int it = 0; it < 2; it++) {
				int nx = i + dx[it], ny = j + dy[it];
				if (!check(nx, ny)) continue;
				if (a[i][j] != a[nx][ny]) continue;
				used[i][j] = 0;
				used[nx][ny] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (used[i][j] != -1) continue;
			for (int it = 0; it < 4; it++) {
				int nx = i + dx[it], ny = j + dy[it];
				if (!check(nx, ny)) continue;
				if (used[nx][ny] == -1) continue;
				need[top1++] = {i, j};
				break;
			}
		}
	}
	while (top1) {
		now++;
		for (int i = 0; i < top1; i++) {
			int x = need[i].first, y = need[i].second;
			used[x][y] = now;
		}

		while (pos < q && Q[pos].t == now) {
			int x = Q[pos].i, y = Q[pos].j;
			if (used[x][y] == -1) {
				ans[Q[pos].ind] = a[x][y];
			} else {
				ans[Q[pos].ind] = get(x, y, now);
			}
			pos++;
		}
		top2 = 0;
		for (int i = 0; i < top1; i++) {
			int x = need[i].first, y = need[i].second;
			for (int it = 0; it < 4; it++) {
				int nx = x + dx[it], ny = y + dy[it];
				if (!check(nx, ny)) continue;
				if (used[nx][ny] != -1) continue;
				used[nx][ny] = now + 1;
				nxt_need[top2++] = {nx, ny};
			}
		}
		for (int i = 0; i < top2; i++) {
			need[i] = nxt_need[i];
		}
		top1 = top2;
	
		/*cout << "a = " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
		cout << endl;*/
	}
	/*cout << "a = " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;*/
}

void run() {
	build();
	/*cerr << "used = " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cerr << used[i][j] << " ";
		}
		cerr << endl;
	}*/
	while (pos < q) {
		ans[Q[pos].ind] = get(Q[pos].i, Q[pos].j, Q[pos].t);
		pos++;
	}
}

void write() {
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.setf(ios::fixed), cout.precision(20);
    read();
    run();
    write();
    return 0;
}

/*
WA 29
input = 
1 5 3
10010
1 4 1
1 5 3
1 3 6

ans =  1
1
0

out =  1
0
0

*/