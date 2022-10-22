#include<bits/stdc++.h>
const int maxn = 301;
using std::cin;
using std::cout;
typedef std::deque<char> AS[maxn];
AS s0[maxn], s1[maxn];
struct pr { int x, y; };
struct ppr { pr x, y; };
std::vector<ppr> v0, v1;
int n, m;
inline void push(std::vector<ppr> & v, AS * s, int x0, int y0, int x1, int y1) {
	s[x1][y1].push_front(s[x0][y0].back());
	s[x0][y0].pop_back();
	v.push_back({{x0 + 1, y0 + 1}, {x1 + 1, y1 + 1}});
}
inline void solve(AS * s, std::vector<ppr> & v) {
	int s0 = s[0][0].size(), s1 = s[0][m - 1].size();
	for(;s0--;)
		if(s[0][0].back() == '1')
			push(v, s, 0, 0, 0, m -1);
		else
			push(v, s, 0, 0, 1, 0);

	for(;s1--;)
		if(s[0][m - 1].back() == '0')
			push(v, s, 0, m - 1, 0, 0);
		else
			push(v, s, 0, m - 1, 1, m - 1);
	for(int i = 0;i < n;++i) {
		for(int j = !i;j + !i < m;++j) {
			for(;s[i][j].size();) {
				if(s[i][j].back() == '0') {
					if(j)
						push(v, s, i, j, i, 0);
					else
						push(v, s, i, j, 0, 0);
				} else {
					if(j != m - 1)
						push(v, s, i, j, i, m - 1);
					else
						push(v, s, i, j, 0, m - 1);
				}
			}
		}
	}
	for(int i = 1;i < n;++i) {
		for(;s[i][0].size();) push(v, s, i, 0, 0, 0);
		for(;s[i][m - 1].size();) push(v, s, i, m - 1, 0, m - 1);
	}
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;++i)
		for(int j = 0;j < m;++j) {
			std::string s; cin >> s;
			for(char x : s) s0[i][j].push_back(x);
		}
	for(int i = 0;i < n;++i)
		for(int j = 0;j < m;++j) {
			std::string s; cin >> s, reverse(s.begin(), s.end());
			for(char x : s) s1[i][j].push_back(x);
		}
	solve(s0, v0);
	solve(s1, v1);
	reverse(v1.begin(), v1.end());
	for(ppr i : v1) {
		std::swap(i.x, i.y);
		v0.push_back(i);
	}
	cout << v0.size() << '\n';
	for(auto i : v0) 
	{
		cout << i.x.x << ' ' << i.x.y << ' ' << i.y.x << ' ' << i.y.y << '\n';
	}
}