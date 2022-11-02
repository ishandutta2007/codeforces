#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N = 611;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int t[N];
bool v[N][N];

int main() {
	int n; cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> t[i];
	set <pair <pair <int, int>, int>> st;
	st.insert({{0, 0}, 0});

	for(int i = 1; i <= n; i ++) {
		set <pair <pair <int, int>, int>> nxt;
		for(auto j : st) {
			int x = j.fi.fi, y = j.fi.se, dir = j.se;
			for(int k = 0; k < t[i]; k ++) {
				x += dx[dir];
				y += dy[dir];
				v[x + 300][y + 300] = 1;
			}
			nxt.insert({{x, y}, (dir + 1) % 8});
			nxt.insert({{x, y}, (dir + 7) % 8});
		}
		st = nxt;
	}
	int ans = 0;
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < N; j ++)
			ans += v[i][j];
	cout << ans << '\n';
}