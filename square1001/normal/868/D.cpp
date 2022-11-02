#include <string>
#include <iostream>
using namespace std;
int n, m, a, b, p[209][16444]; string s, ss[109], ls[209], rs[209];
void add(int pos, string x) {
	for (int i = 0; i < x.size(); i++) {
		for (int j = 1; j <= 13 && j <= x.size(); j++) {
			for (int k = j; k <= x.size(); k++) {
				int bit = 0;
				for (int l = 0; l < j; l++) {
					if (x[k - j + l] == '1') bit += 1 << l;
				}
				p[pos][(1 << j) + bit] = 1;
			}
		}
	}
}
int solve(int x) {
	int res = -1;
	for (int i = 2; ; i++) {
		if (p[x][i] == 0) {
			res = i;
			break;
		}
	}
	int ret = 0;
	while ((4 << ret) <= res) ret++;
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ss[i]; s = ss[i];
		if (s.size() < 13) ls[i] = s, rs[i] = s;
		else ls[i] = s.substr(0, 13), rs[i] = s.substr(s.size() - 13);
		add(i, ss[i]);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b; a--, b--;
		for (int j = 0; j <= 16384; j++) {
			if (p[a][j] == 1) p[n + i][j] = 1;
			if (p[b][j] == 1) p[n + i][j] = 1;
		}
		add(n + i, rs[a] + ls[b]);
		s = (ls[a].size() < 13 ? ls[a] : ls[a] + rs[a]) + (rs[b].size() < 13 ? rs[b] : ls[b] + rs[b]);
		if (s.size() < 13) ls[n + i] = s, rs[n + i] = s;
		else ls[n + i] = s.substr(0, 13), rs[n + i] = s.substr(s.size() - 13);
		add(n + i, ls[n + i]);
		add(n + i, rs[n + i]);
		cout << solve(n + i) << endl;
	}
	return 0;
}