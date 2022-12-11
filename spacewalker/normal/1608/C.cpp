#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1000000001;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<tuple<int, int, int>> players; // (a, i, b)
		vector<int> astr(n), bstr(n);
		for (int i = 0; i < n; ++i) scanf("%d", &astr[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &bstr[i]);
		for (int i = 0; i < n; ++i) players.emplace_back(astr[i], i, bstr[i]);
		sort(begin(players), end(players));
		int lastCutPoint = -1; // everyone after this point can win
		vector<int> pfmax(n), sfmin(n);
		for (int i = 0; i < n; ++i) {
			auto [as, pid, bs] = players[i];
			pfmax[i] = max(i == 0 ? -1 : pfmax[i-1], bs);
		}
		for (int i = n-1; i >= 0; --i) {
			auto [as, pid, bs] = players[i];
			sfmin[i] = min(i == n-1 ? INF : sfmin[i+1], bs);
		}
		for (int i = 0; i + 1 < n; ++i) if (pfmax[i] < sfmin[i+1]) lastCutPoint = i;
		vector<bool> ans(n);
		for (int i = lastCutPoint + 1; i < n; ++i) {
			auto [as, pid, bs] = players[i];
			ans[pid] = true;
		}
		for (bool b : ans) printf("%c", b ? '1' : '0');
		printf("\n");
	}
}