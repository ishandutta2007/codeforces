#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
const int limit = 100000;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
	long long ans = 0;
	for (int parity = 0; parity < 2; ++parity) {
		vector<int> sx, sy;
		for (int i = 0; i < N; ++i) {
			if ((X[i] + Y[i] + limit * 2) % 2 == parity) {
				sx.push_back((X[i] + Y[i] + limit * 2) / 2);
				sy.push_back((X[i] - Y[i] + limit * 2) / 2);
			}
		}
		vector<vector<int> > g(limit * 2 + 1);
		for (int i = 0; i < sx.size(); ++i) {
			g[sx[i]].push_back(sy[i]);
		}
		vector<int> ul(limit * 2 + 2, inf), ur(limit * 2 + 2, -inf), dl(limit * 2 + 2, inf), dr(limit * 2 + 2, -inf);
		for (int i = 0; i <= limit * 2; ++i) {
			ul[i + 1] = ul[i]; ur[i + 1] = ur[i];
			for (int j : g[i]) {
				ul[i + 1] = min(ul[i + 1], j);
				ur[i + 1] = max(ur[i + 1], j);
			}
		}
		for (int i = limit * 2; i >= 0; --i) {
			dl[i] = dl[i + 1]; dr[i] = dr[i + 1];
			for (int j : g[i]) {
				dl[i] = min(dl[i], j);
				dr[i] = max(dr[i], j);
			}
		}
		for (int i = 1; i <= limit * 2; ++i) {
			int pl = max(ul[i], dl[i]), pr = min(ur[i], dr[i]);
			if (pl < pr) ans += pr - pl;
		}
	}
	cout << ans << endl;
	return 0;
}