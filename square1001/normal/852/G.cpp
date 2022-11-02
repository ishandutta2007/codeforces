#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int N, M, c, p[5], res; ull ph[5], pw[100009]; string s; map<ull, int> d; set<ull> g;
void dfs(int pos, ull cum) {
	if (pos == c + 1) {
		if (!g.count(cum)) {
			g.insert(cum);
			res += d[cum];
		}
		return;
	}
	dfs(pos + 1, cum * pw[p[pos + 1] - p[pos] - 1] + ph[pos]);
	for (int i = 97; i <= 101; i++) {
		dfs(pos + 1, (cum * 263 + i) * pw[p[pos + 1] - p[pos] - 1] + ph[pos]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	pw[0] = 1;
	for (int i = 1; i <= 50; i++) pw[i] = pw[i - 1] * 263;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		ull h = 0;
		for (int j = 0; j < s.size(); j++) h = h * 263 + s[j];
		d[h]++;
	}
	for (int i = 0; i < M; i++) {
		cin >> s; c = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '?') p[++c] = j;
		}
		p[0] = -1; p[c + 1] = s.size();
		for (int j = 0; j <= c; j++) {
			ph[j] = 0;
			for (int k = p[j] + 1; k < p[j + 1]; k++) ph[j] = ph[j] * 263 + s[k];
		}
		res = 0; g.clear();
		dfs(1, ph[0]);
		cout << res << endl;
	}
	return 0;
}