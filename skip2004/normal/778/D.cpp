#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200;
typedef char AC[maxn][maxn];
typedef std::pair<int, int> pr;
typedef std::vector<pr> vec;
AC s0, s1;
int n, m, swap;
inline void flip(int x, int y, AC & s, vec & v) {
	v.emplace_back(x, y);
	if(s[x][y] == 'L') {
		s[x][y] = s[x][y + 1] = 'U';
		s[x + 1][y] = s[x + 1][y + 1] = 'D';
	} else {
		s[x][y] = s[x + 1][y] = 'L';
		s[x][y + 1] = s[x + 1][y + 1] = 'R';
	}
}
inline void dfs(int x, int y, AC & s, vec & v) {
	if(s[x][y] == 'L') return ;
	if(s[x][y + 1] == 'U') return flip(x, y, s, v);
	dfs(x + 1, y + 1, s, v), flip(x, y + 1, s, v), flip(x, y, s, v);
}
inline vec solve(AC& s) {
	vec now;
	for(int i = 0;i < n;++i) for(int j = 0;j < m;++j) if(s[i][j] == 'U') {
		dfs(i, j, s, now);
	}
	return now;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if(m % 2 == 1) {
		std::map<char, char> map = { {'U', 'L'}, {'L', 'U'}, {'D', 'R'}, {'R', 'D'} };
		for(int i = 0;i < n;++i) for(int j = 0;j < m;++j) cin >> s0[j][i], s0[j][i] = map[s0[j][i]];
		for(int i = 0;i < n;++i) for(int j = 0;j < m;++j) cin >> s1[j][i], s1[j][i] = map[s1[j][i]];
		std::swap(n, m);
		swap = 1;
	} else {
		for(int i = 0;i < n;++i) for(int j = 0;j < m;++j) cin >> s0[i][j];
		for(int i = 0;i < n;++i) for(int j = 0;j < m;++j) cin >> s1[i][j];
	}
	vec v0 = solve(s0);
	vec	v1 = solve(s1);
	reverse(v1.begin(), v1.end());
	cout << v0.size() + v1.size() << '\n';
	for(pr i : v0) {
		if(swap) {
			std::swap(i.first, i.second);
		}
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	}
	for(pr i : v1) {
		if(swap) {
			std::swap(i.first, i.second);
		}
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	}
}